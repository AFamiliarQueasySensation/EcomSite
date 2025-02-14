#include "../src/webserver.h"
#include "../src/handleClient.h"
#include <QTcpServer>

#define PORT 80

WebServer::WebServer(QObject *parent) : QObject(parent), m_server(std::make_unique<QTcpServer>())
{

    connect(m_server.get(), &QTcpServer::newConnection,this, &WebServer::newConnection);
    
}

WebServer::~WebServer() {}

/**
 * Server Start, Listeing on port specified above currently on any host address
 * 
 */
void WebServer::serverStart(){
    if (!m_server->listen(QHostAddress::Any, PORT)){
        qDebug() << "Error: " << m_server->errorString();
    }
    else{
        qDebug() << "Currently listening on 10184";
    }
    

}

/**
 * Listener class, and calls handle class from handleClient, on the new connection.
 */

void WebServer::newConnection(){
    const auto socket = m_server->nextPendingConnection();
    

    if (!socket){
        return;
    }
    
    new handleClient(socket);

}
