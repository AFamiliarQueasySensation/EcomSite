#include <iostream>
#include <QCoreApplication>
#include <QIcon>
#include "../src/webserver.h"

int main(int argc, char* argv[]){
    QCoreApplication a(argc, argv);

    WebServer server;
    server.serverStart();
    


    a.exec();
}
