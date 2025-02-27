#include "../src/handleClient.h"

#include <QTcpSocket>
#include <QCoreApplication>
#include <QRegularExpression>
#include <QFile>
#include <QUrl>
#include <QDir>
#include <QThread>
#include <QFileINfo>
#include <QDebug>
#include <QtLogging>
#include <QEventLoop>

handleClient::handleClient(QObject *parent) : QObject(parent)
{
}

handleClient::~handleClient()
{
    qInfo() << this << Q_FUNC_INFO << QThread::currentThread();
    m_socket->deleteLater();
}

/**
 * This is what a QThreadPool Calls, thorugh a signal
 */
void handleClient::run()
{
    qInfo() << this << Q_FUNC_INFO << "In Run " << QThread::currentThread();

    m_socket = new QTcpSocket();
    if (!m_socket->setSocketDescriptor(this->socketDescriptor))
    {
        qWarning() << "Error setting socket descriptor:" << m_socket->errorString();
        delete m_socket;
        return;
    }

    m_socket->moveToThread(QThread::currentThread());

    // Plumb the disconnect with delete later
    //Apparently adding waitForReadyRead makes it a direct connection not queued connection because as soon as it hits, it goes directly to readyRead
    QObject::connect(m_socket, &QIODevice::readyRead, this, &handleClient::readReady, Qt::DirectConnection);
    m_socket->waitForReadyRead();

    qInfo() << this << "Handling Client On" << QThread::currentThread();

}

/**
 * Main client reading, where im parsing the request
 * Socket has everything you need to read from the client, and what they want
 * using m_state to keep track of the current state that the parse is in
 */

void handleClient::readReady()
{
    qInfo() << this << "Reading on: " << QThread::currentThread();
    while ((m_state == ConnectionState::RequestLine || m_state == ConnectionState::RequestHeaders) && m_socket->canReadLine())
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
            // Finished Going through Headers (Body delimiter i forgot what it called its when u got two \r\n)
            if (line.isEmpty())
            {
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

                else
                {
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
            qDebug() << "Here";
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
 
    qInfo() << this << "Sending Reply OK: " << QThread::currentThread();
    QString content;

    content += "<H1> Hello </H1>";

    const auto encode = content.toUtf8();
    m_socket->write("HTTP/1.1 200 OK\r\n");
    m_socket->write("Content-Type: text/html\r\n");
    m_socket->write(QString("Content-Length: %0\r\n").arg(encode.size()).toUtf8());
    m_socket->write("Connection: close\r\n");
    m_socket->write("\r\n");
    m_socket->write(encode);


    m_state = ConnectionState::RequestLine;
    m_request = {}; 

    m_socket->waitForBytesWritten();

}

/**
 * Error reply for unknown webpage
 */
void handleClient::sendNotFound()
{
    QString content;
    content += "<H1> Error 404 </H1>";
    
    const auto encode = content.toUtf8();
    m_socket->flush();
    m_socket->write("HTTP/1.1 404 Not Found\r\n");
    m_socket->write("Content-Type: text/html\r\n");
    m_socket->write(QString("Content-Length: %0\r\n").arg(encode.size()).toUtf8());
    m_socket->write("\r\n");
    m_socket->write(encode);
    m_socket->waitForBytesWritten();


}

