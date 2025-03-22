#include "ItemInfo.h"
#include "ItemSearch.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QDebug>

//request url
namespace {
    const QString &requesturl = "https://<arg>.myshopify.com/products.json";
    const QString &client_id = "";
}



ItemSearch::ItemSearch(QObject *parent)
{

    for (int i = 0; i < 7 ; i++){
        ItemInfo *item1 = new ItemInfo(this);
        item1->setSellerName("Example1");
        item1->setItemName("Item1");
        item1->setImageSource(QUrl("https://cdn.shopify.com/s/files/1/0098/8822/files/LiftingOversizedWovenPantGSStrengthGreenA6A3R-ECJH-1068_1042f630-aee4-41ec-8975-c9b42f353971.jpg?v=1713881558"));
        item1->setVideoSource(QUrl(""));
        item1->setGifSource(QUrl(""));


        m_itemList.append(item1);
    }




}

int ItemSearch::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_itemList.size();
}

QVariant ItemSearch::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && index.row() >= 0 && index.row() < m_itemList.size()){
        ItemInfo *itemInfo = m_itemList[index.row()];

        switch ((Role)role) {
            case ItemNameRole:
                return itemInfo->itemName();
            case ItemAuthorRole:
                return itemInfo->sellerName();
            case ItemImageSourceRole:
                return itemInfo->imageSource();
            case ItemSourceRole:
                return itemInfo->gifSource();
            case ItemVideoSourceRole:
                return itemInfo->videoSource();
        }
    }
    return {};
}

QHash<int, QByteArray> ItemSearch::roleNames() const
{

    QHash<int, QByteArray> names;
    names[ItemNameRole] = "itemTitle";
    names[ItemAuthorRole] = "itemSeller";
    names[ItemImageSourceRole] = "itemImageSource";
    names[ItemSourceRole] = "itemGifSource";
    names[ItemVideoSourceRole] = "itemVideoSource";

    return names;
}

void ItemSearch::searchItems(const QString &name)
{

    if (!name.isEmpty())
        {
            if (m_reply)
            {
                m_reply->abort();
                m_reply->deleteLater();
                m_reply = nullptr;
            }

            QUrlQuery query;
            query.addQueryItem("client_id", client_id);
            query.addQueryItem("item_name", name);
            query.addQueryItem("format", "json");
            setIsSearching(true);

            /* Name is the name of the site you want, you literally jst do it like that and it will reutrn something if it got something*/
            m_reply = m_networkManager.get(QNetworkRequest(QString("https://%1.myshopify.com/products.json").arg(name)));

            connect(m_reply, &QNetworkReply::finished, this, &ItemSearch::parseData);


        }
}

void ItemSearch::parseData()
{
    setIsSearching(false);

    return;
    if (m_reply->error() == QNetworkReply::NoError){
        beginResetModel();

        qDeleteAll(m_itemList);
        m_itemList.clear();

        QByteArray data = m_reply->readAll();

        QJsonDocument jsonDocument = QJsonDocument::fromJson(data);

        /* Two Main headers, and results*/
        /* Check if header successful first*/

        QJsonObject headers = jsonDocument["headers"].toObject();

        if (headers["status"] == "success") {
            QJsonArray result = jsonDocument["results"].toArray();

            for (const auto &i : result) {
                /*try to send back more than one reply */
                QJsonObject entry = i.toObject();
                ItemInfo *itemInfo = new ItemInfo(this);

                itemInfo->setItemName(entry["item_name"].toString());
                itemInfo->setSellerName(entry["seller_name"].toString());
                itemInfo->setImageSource(entry["image_source"].toString());
                itemInfo->setGifSource(entry["gif_source"].toString());
                itemInfo->setVideoSource(entry["video_source"].toString());


                m_itemList << itemInfo;

            }


        } else {
            qCritical() << "Error in ItemSearching ParseData: " << m_reply->errorString();

        }
        endResetModel();
        m_reply->deleteLater();
        m_reply = nullptr;
    }
}

bool ItemSearch::isSearching() const
{
    return m_isSearching;
}

void ItemSearch::setIsSearching(bool newIsSearching)
{
    if (m_isSearching == newIsSearching)
        return;
    m_isSearching = newIsSearching;
    emit isSearchingChanged();
}
