#include "../src/webserver.h"
#include "../src/handleClient.h"

#define PORT 80
#define MAX_THREAD_COUNT 5

WebServer::WebServer(QObject *parent) : QTcpServer(parent)
{
    qInfo() << this << "Created Server on: " << QThread::currentThread();
    QThreadPool::globalInstance()->setMaxThreadCount(MAX_THREAD_COUNT);
}

WebServer::~WebServer() {}

/**
 * Server Start, Listeing on port specified above currently on any host address
 *
 */
void WebServer::serverStart()
{
    if (this->listen(QHostAddress::Any, PORT))
    {
        qDebug() << "Currently listening on " << PORT;
    }
    else
    {
        qDebug() << "Error: " << this->errorString();
    }
}

/**
 * Listener class, and calls handle class from handleClient, on the new connection.
 */

void WebServer::incomingConnection(qintptr handle)
{
    qInfo() << this << Q_FUNC_INFO << "Accepted new connection " << QThread::currentThread();

    handleClient *client = new handleClient();
    client->setAutoDelete(true);
    client->socketDescriptor = handle;
    QThreadPool::globalInstance()->start(client);
}
