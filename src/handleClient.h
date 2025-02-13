#pragma once

#include <QObject>

class QTcpSocket;


class handleClient: public QObject{

    Q_OBJECT

    public:
        explicit handleClient(QTcpSocket *socket, QObject *parent = nullptr);
        ~handleClient() override;

    private slots:
        void readReady();


    private:
        const std::unique_ptr<QTcpSocket> m_socket;


};

