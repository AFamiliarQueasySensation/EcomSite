#include "../src/httpsServer.h"
#include "../src/handleClient.h"
#include "httpsServer.h"
#include <QFile>
#include <QByteArray>
#include <QSslKey>
#include <QDir>
#include <QThreadPool>


#define PORT 443
#define MAX_THREAD_COUNT 5

httpsServer::httpsServer(QObject *parent) 
    : QSslServer(parent)
{
    qInfo() << "Generating a https server on thread: " << QThread::currentThreadId();
    QThreadPool::globalInstance()->setMaxThreadCount(MAX_THREAD_COUNT);


    m_config = this->sslConfiguration();

    //Load Certificate
    QFile certFile("../keys/fullchain.pem");
    if (certFile.open(QIODevice::ReadOnly))
    {
        QByteArray certData = certFile.readAll();
        QSslCertificate certificate(certData, QSsl::Pem);
        m_config.addCaCertificate(certificate);
    }


    //Private key
    QFile keyFile("../keys/cert-key.pem");
    if (keyFile.open(QIODevice::ReadOnly))
    {
        QByteArray keyData = keyFile.readAll();
        QSslKey key(keyData, QSsl::Rsa, QSsl::Pem, QSsl::PrivateKey);
        m_config.setPrivateKey(key);
    }

    m_config.setProtocol(QSsl::TlsV1_3); // wha tthe fuck is tlsv1_3

    qDebug() << m_config.localCertificate();




    this->setSslConfiguration(m_config);
    
}

void httpsServer::startServer()
{
    if (this->listen(QHostAddress::Any, PORT)){
        qInfo() << "Listening on Port:" << PORT << "Thread:" << QThread::currentThread();
    }
    else{
        qCritical() << "Failed to bind to port: " << PORT;
        return;
    }

}

void httpsServer::incomingConnection(qintptr handle)
{
    qInfo() << this << Q_FUNC_INFO << "Accepted Https new connection " << QThread::currentThread();

    handleClient *client = new handleClient();
    client->setAutoDelete(true);
    client->socketDescriptor = handle;
    QThreadPool::globalInstance()->start(client);


}