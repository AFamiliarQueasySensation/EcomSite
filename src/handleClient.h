#pragma once

#include <QObject>
#include <QMap>
#include <QByteArray>

class QTcpSocket;

class handleClient : public QObject
{

    Q_OBJECT

public:
    explicit handleClient(QTcpSocket *socket, QObject *parent = nullptr);
    ~handleClient() override;

private slots:
    void readReady();

private:
    void sendResponse();
    void sendfavico();
    void sendNotFound();
    const std::unique_ptr<QTcpSocket> m_socket;


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
