#pragma once

#include <QtCore/QObject>
#include <memory>
#include <QDebug>


class QTcpServer;

class WebServer : public QObject
{
    Q_OBJECT

    public: 

        explicit WebServer(QObject *parent = nullptr);
        ~WebServer();
        void serverStart();

    private:
        void newConnection();


    
    private:
        std::unique_ptr<QTcpServer> m_server; //Apparently unique ptrs seld delete at the end of the scope
        int port;

};