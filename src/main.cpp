#include <QCoreApplication>
#include <QThreadPool>
#include <QtConcurrent>
#include <QThread>
#include <QSettings>
#include <QDir>
#include <QString>
#include "../src/webserver.h"


int main(int argc, char* argv[]){
    QCoreApplication a(argc, argv);
    
    QThread::currentThread()->setObjectName("Main Thread");

    WebServer *server = new WebServer();
    server->serverStart();



    
    a.exec();
    
}
