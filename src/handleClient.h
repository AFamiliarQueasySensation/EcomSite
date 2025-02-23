#pragma once

#include <QObject>
#include <QMap>
#include <QByteArray>
#include <QRunnable>

class QTcpSocket;

class handleClient : public QObject, public QRunnable
{

    Q_OBJECT

public:
    explicit handleClient(QObject *parent = nullptr);
    ~handleClient() override;
    void run() Q_DECL_OVERRIDE;

    qintptr socketDescriptor;

private slots:
    void readReady();


private:
    void sendResponse();
    void sendfavico();
    void sendNotFound();
    QTcpSocket *m_socket;
    


    struct Request {
        std::size_t contentLength{};

        QString method;
        QString path;
        QString protocol;

        QMap<QString, QString> headers;
        QByteArray body;
    };

    Request m_request;

    enum ConnectionState {
        RequestLine,
        RequestHeaders,
        RequestBody,
        Response
    };

    ConnectionState m_state{ConnectionState::RequestLine};
};
