#pragma once

#include <QtCore/QObject>
#include <memory>
#include <QThread>
#include <QTcpServer>
#include <QTcpSocket>
#include <QThreadPool>
#include <QDebug>



class WebServer : public QTcpServer
{
    Q_OBJECT

public:
    explicit WebServer(QObject *parent = nullptr);
    ~WebServer();
    void serverStart();


protected:
    void incomingConnection( qintptr handle ) override;

};