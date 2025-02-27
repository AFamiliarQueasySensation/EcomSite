#include <QCoreApplication>
#include <QThread>
#include <QSettings>
#include <QString>
#include "../src/webserver.h"
#include "../src/httpsServer.h"


int main(int argc, char* argv[]){
    QCoreApplication a(argc, argv);
    
    
    
    QThread::currentThread()->setObjectName("Main Thread");

    WebServer *server = new WebServer();
    server->serverStart();

    
     
    
    
  
        
    QThread::currentThread()->setObjectName("Main Thread");
   
    httpsServer *httpsserver = new httpsServer();
    httpsserver->startServer();

    



    
    a.exec();
    
}
