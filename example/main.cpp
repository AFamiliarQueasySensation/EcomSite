#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>
#include "ItemController.h"
#include "ItemSearch.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);



    app.setWindowIcon(QIcon("C:/Users/vonha/Documents/example/assets/icons/favicon.ico"));

    QQmlApplicationEngine engine;


    QScopedPointer<ItemController> itemController(new ItemController());
    qmlRegisterSingletonInstance("com.company.ItemController", 1, 0, "ItemController", itemController.get());
    QScopedPointer<ItemSearch> itemSearch(new ItemSearch());
    qmlRegisterSingletonInstance("Qt.example.ItemSearch",1,0,"ItemSearch", itemSearch.get());


    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("example", "Main"); // Make sure EXAMPLE is the name of your directory that Main.qml is in or else it says fuck you, and make sure its also same in cmake



    return app.exec();

}
