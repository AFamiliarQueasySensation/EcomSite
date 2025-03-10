#include <QHttpServer>
#include <QHttpServerResponse>

#include <QSslCertificate>
#include <QSslKey>
#include <QSslServer>

#include <QCoreApplication>
#include <QFile>
#include <QJsonObject>
#include <QString>
#include <QTcpServer>

using namespace Qt::StringLiterals;

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);

    QHttpServer httpServer;

    // This will route to the main website page "ex google.com/"
    httpServer.route("/",[](){
        return "Hello World";
    });

    // This will route to a sub directory "ex google.com/assets/something"
    httpServer.route("/assets/<arg>", [] (const QUrl &url) {
        return QHttpServerResponse::fromFile(u"/Users/grantvonhagen/assets/"_s + url.path());
    }); 

    //If you want to implement here just do something like what path you the getter will become and then return the file 
    // Ex. a request could look like "GET /something.js HTTP/1.1", just put "/something.js" and then return the QHTTPserverResponse
    // From the file like I do above for a file like something.js
    // Dont forget to add it to the CMakeLists.txt




    




    /**
     * This is all for initializing the server dont mess with 
     */
    auto tcpserver = std::make_unique<QTcpServer>();
    if (!tcpserver->listen(QHostAddress::Any, 8080) || !httpServer.bind(tcpserver.get())){
        qWarning() << QCoreApplication::translate("QHttpServer", 
                                                                "Failed to listen on a port");
        return -1;
    }
    quint16 port = tcpserver->serverPort();
    tcpserver.release();

    QSslConfiguration conf = QSslConfiguration::defaultConfiguration();
    const auto sslCertificateChain = QSslCertificate::fromPath(QStringLiteral("/Users/grantvonhagen/keys/certificate.crt"));
    if (sslCertificateChain.empty()){
        qWarning() << QCoreApplication::translate("QHttpServer",
                                                                "Couldn't retrieve SSL certificate from file.");
        return -1;
    }
    QFile privateKeyFile(QStringLiteral("/Users/grantvonhagen/keys/private.key"));
    if (!privateKeyFile.open(QIODevice::ReadOnly)) {
        qWarning() << QCoreApplication::translate("QHttpServer",
                                                                "Couldn't open file for reading: %1")
                      .arg(privateKeyFile.errorString());
        return -1;
    }

    conf.setLocalCertificate(sslCertificateChain.front());
    conf.setPrivateKey(QSslKey(&privateKeyFile, QSsl::Rsa));
    privateKeyFile.close();

    auto sslserver = std::make_unique<QSslServer>();
    sslserver->setSslConfiguration(conf);
    if (!sslserver->listen(QHostAddress::Any, 443) || !httpServer.bind(sslserver.get())){
         qWarning() << QCoreApplication::translate("QHttpServer",
                                                                "Server failed to listen on a port.");
        return -1;
    }
    quint16 sslPort = sslserver->serverPort();
    sslserver.release();

    qInfo().noquote()
        << QCoreApplication::translate("QHttpServerExample",
                                       "Running on http://127.0.0.1:%1/ and "
                                       "https://127.0.0.1:%2/ (Press CTRL+C to quit)")
           .arg(port).arg(sslPort);


    return a.exec();
}
