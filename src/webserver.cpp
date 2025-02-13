#include "../src/webserver.h"
#include "../src/handleClient.h"
#include <QTcpServer>

#define PORT 8080

WebServer::WebServer(QObject *parent) : QObject(parent), m_server(std::make_unique<QTcpServer>())
{

    connect(m_server.get(), &QTcpServer::newConnection,this, &WebServer::newConnection);
    
}

void WebServer::serverStart(){
    m_server->listen(QHostAddress::Any, PORT);
}


void WebServer::newConnection(){
    const auto socket = m_server->nextPendingConnection();
    if (!socket){
        return;
    }
    new handleClient(socket);

}

WebServer::~WebServer()
{}