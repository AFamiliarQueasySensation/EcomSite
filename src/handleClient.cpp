#include "../src/handleClient.h"

#include <QTcpSocket>
#include <QDebug>

handleClient::handleClient(QTcpSocket *socket, QObject *parent) : QObject(parent), m_socket(socket)
{
    connect(m_socket.get(), &QAbstractSocket::disconnected, this, &QObject::deleteLater);
    connect(m_socket.get(), &QIODevice::readyRead, this, &handleClient::readReady);
    
}


void handleClient::readReady()
{
    while(m_socket->canReadLine()){

        const auto line = m_socket->readLine();
        if (line == "\r\n"){

            m_socket->write("HTTP/1.1 200 OK \r\n");
            m_socket->write("Connection: keep-alive\r\n");
            m_socket->write("Content-Length: 10\r\n");
            m_socket->write("\r\n"); //end header
            m_socket->write("Fuck yo bitch ass ");
            m_socket->flush();

        }




    }
}



handleClient::~handleClient(){}