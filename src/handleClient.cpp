#include "../src/handleClient.h"

#include <QTcpSocket>
#include <QCoreApplication>
#include <QRegularExpression>
#include <QFile>
#include <QUrl>
#include <QDir>
#include <QFileINfo>
#include <QDebug>

handleClient::handleClient(QTcpSocket *socket, QObject *parent) : QObject(parent), m_socket(socket)
{
    connect(m_socket.get(), &QAbstractSocket::disconnected, this, &QObject::deleteLater);
    connect(m_socket.get(), &QIODevice::readyRead, this, &handleClient::readReady);
}

handleClient::~handleClient() {}

/**
 * Main client reading, where im parsing the request
 */
void handleClient::readReady()
{
    while ((m_state == ConnectionState::RequestLine || m_state == ConnectionState::RequestHeaders) && m_socket.get()->canReadLine())
    {

        auto line = m_socket->readLine();
        if (line.endsWith("\r\n")) // chop delimiter
        {
            line.chop(2);
        }
        


        
        // method, path, protocol
        if (m_state == ConnectionState::RequestLine)
        {
            const auto parts = line.split(' ');

            if (parts.size() != 3)
            {
                qDebug() << "Error in RequestLine (maybe wrong type?): " << line;
                deleteLater();
                return;
            }
            // handle parts, protocol, and path
            m_request.method = parts.at(0);
            m_request.path = parts.at(1);
            m_request.protocol = parts.at(2);

            m_state = ConnectionState::RequestHeaders; // Change to RequestHeaders
            continue;
        }
        else
        {
            //Finished Going through Headers (Body delimiter i forgot what it called its when u got two \r\n)
            if (line.isEmpty())
            {
                qDebug() << m_request.path;
                if (m_request.contentLength)
                {
                    m_state = ConnectionState::RequestBody;
                    continue;
                }
                if (m_request.path == "/")
                {
                    sendResponse();
                    return;
                }
               
                else{
                    sendNotFound();
                    return;
                }

            }
            
            static const QRegularExpression expr("^([^:]+): +(.*)$");
            const auto match = expr.match(line);
            if (!match.hasMatch())
            {
                qDebug() << "No match found in expression matching, handleClient.cpp";
                deleteLater();
                return;
            }

            const auto name = match.captured(1);
            const auto value = match.captured(2);


            m_request.headers[name] = value;

            if (name == "Content-Length")
            {
                bool ok;
                m_request.contentLength = value.toInt(&ok);

                if (!ok)
                {
                    qDebug() << "Could not parse Content-Length in handleClient.cpp: " << line;
                    deleteLater();
                    return;
                }
            }

            continue;
        }
    }

    // Parse body
    if (m_state == ConnectionState::RequestBody)
    {
        m_request.body.append(m_socket->read(m_request.contentLength - m_request.body.size()));

        if (m_request.body.size() == m_request.contentLength)
        {

            m_state = ConnectionState::Response;
            sendResponse();
            return;
        }
    }
}

/**
 * Default path response, like default webpage "/"
 */
void handleClient::sendResponse()
{
    QString content;
    
    content += "<H1>Testing</H1>";
    
    const auto encode = content.toUtf8();
    m_socket->write("HTTP/1.1 200 OK\r\n");
    m_socket->write("Content-Type: text/html\r\n");
    m_socket->write(QString("content-Length: %0\r\n").arg(encode.size()).toUtf8());
    m_socket->write("\r\n");
    m_socket->write(encode);
    m_state = ConnectionState::RequestLine;
    m_request = {};

}



/**
 * Error reply for unknown webpage
 */
void handleClient::sendNotFound(){
    QString content;
    content += "<H1> Error 404 </H1>";

    const auto encode = content.toUtf8();
    m_socket->write("HTTP/1.1 404 Not Found\r\n");
    m_socket->write("Content-Type: text/html\r\n");
    m_socket->write(QString("Content-Length: %0\r\n").arg(encode.size()).toUtf8());
    m_socket->write("\r\n");
    m_socket->write(encode);
    m_socket->disconnectFromHost();
}