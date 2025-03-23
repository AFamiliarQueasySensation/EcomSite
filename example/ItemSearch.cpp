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
{}

int ItemSearch::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_itemList.size();
}

QVariant ItemSearch::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && index.row() >= 0 && index.row() < m_itemList.size()){
        ItemInfo *itemInfo = m_itemList[index.row()];

        switch ((ItemRole)role) {
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
        case ItemIndexRole:
            return itemInfo->itemIndex();
        case ItemIdRole:
            return itemInfo->itemId();
        case ItemDescriptionRole:
            return itemInfo->description();
        case ItemProductTypeRole:
            return itemInfo->productType();
        case ItemCreatedAtRole:
            return itemInfo->createdAt();
        case ItemTagsRole:
            return itemInfo->tags();
        case ItemSizesRole:
            return itemInfo->sizes();
        case ItemPricesRole:
            return itemInfo->prices();
        case ItemImageGalleryRole:
            return QVariant::fromValue(itemInfo->imageGallery()); // mot sure this gonna work
        case ItemSellerNameRole:
            return itemInfo->sellerName();
        case ItemGifSourceRole:
            return itemInfo->gifSource();
        default:
            return QVariant();
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
    names[ItemIndexRole] = "index";
    names[ItemIdRole] = "itemId";
    names[ItemDescriptionRole] = "description";
    names[ItemProductTypeRole] = "productType";
    names[ItemCreatedAtRole] = "createdAt";
    names[ItemTagsRole] = "tags";
    names[ItemSizesRole] = "sizes";
    names[ItemPricesRole] = "prices";
    names[ItemImageGalleryRole] = "imageGallery";
    names[ItemSellerNameRole] = "sellerName";
    names[ItemGifSourceRole] = "gifSource";

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


            setIsSearching(true);

            /* Name is the name of the site you want, you literally jst do it like that and it will reutrn something if it got something*/
            m_reply = m_networkManager.get(QNetworkRequest(QString("https://%1.myshopify.com/products.json").arg(name)));

            connect(m_reply, &QNetworkReply::finished, this, &ItemSearch::parseData);


        }
}

void ItemSearch::parseData()
{


    if (m_reply->error() == QNetworkReply::NoError){
        //beginresetmodel, means any previous data reporteed from the model is now invalid and has to be queried again.
        beginResetModel();
        qDeleteAll(m_itemList);
        m_itemList.clear();

        QByteArray data = m_reply->readAll();
        QJsonDocument jsonDocument = QJsonDocument::fromJson(data);
        QJsonArray products = jsonDocument["products"].toArray();
        int index = 0;

        //Parse Data Here
        for (const QJsonValue &value : products) {
            QJsonObject obj = value.toObject();
            ItemInfo *item = new ItemInfo(this);
            //Default to no images
            item->setVideoSource(QUrl(""));
            item->setGifSource(QUrl(""));
            item->setImageSource(QUrl(""));

            //Product Descriptions
            item->setItemName(obj["title"].toString());
            item->setItemId(QString::number(obj["id"].toVariant().toLongLong()));
            item->setDescription(obj["body_html"].toString());
            item->setProductType(obj["product_type"].toString());
            item->setCreatedAt(obj["created_at"].toString());
            item->setSellerName(obj["vendor"].toString());

            //Tags
            QJsonArray tagsArray = obj["tags"].toArray();
            QStringList tagList;
            for (const QJsonValue &t : tagsArray)
                tagList.append(t.toString());
            item->setTags(tagList);

            //Variants, Sizes, Prices
            QJsonArray variants = obj["variants"].toArray();
            QStringList sizes;
            QStringList prices;
            for (const QJsonValue &v : variants) {
                QJsonObject varObj = v.toObject();
                sizes.append(varObj["title"].toString());
                prices.append(varObj["price"].toString());
            }
            item->setSizes(sizes);
            item->setPrices(prices);

            //Images
            QJsonArray images = obj["images"].toArray();
            QList<QUrl> imageUrls;
            for (const QJsonValue &imgVal : images) {
                QJsonObject img = imgVal.toObject();
                imageUrls.append(QUrl(img["src"].toString()));
            }
            item->setImageSource(imageUrls.front());
            item->setImageGallery(imageUrls);

            m_itemList.append(item);
        }


        setIsSearching(false);
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
