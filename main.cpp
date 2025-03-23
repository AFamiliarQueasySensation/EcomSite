#include <QCoreApplication>
#include <QtQml>
#include "ItemSearch.h"
#include "ItemInfo.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qmlRegisterType<ItemInfo>("Shopify", 1, 0, "ItemInfo");

    ItemSearch search;
    search.searchItems("gymshark");  // This hits https://gymshark.myshopify.com/products.json

    return a.exec();
}
