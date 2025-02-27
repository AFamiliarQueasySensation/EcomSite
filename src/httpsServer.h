#ifndef HTTPS_SERVER_H
#define HTTPS_SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QSslServer>
#include <QSslSocket>
#include <QSsl>
#include <QThread>
#include <QDebug>


class httpsServer : public QSslServer
{
    Q_OBJECT

public:
    explicit httpsServer(QObject *parent=nullptr);
    void startServer();

protected:
    void incomingConnection(qintptr socketDesctiptor) override;


private:

    QSslConfiguration m_config;



};




#endif //HTTPS_SERVER_H