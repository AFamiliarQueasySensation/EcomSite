#include "ItemInfo.h"
#include "ItemSearch.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QDebug>
#include <QFile>

// request url
namespace {
const QString &requesturl = "https://<arg>.myshopify.com/products.json";
const QString &client_id = "";
}

ItemSearch::ItemSearch(QObject *parent)
    : QAbstractListModel(parent), m_reply(nullptr), m_isSearching(false)
{
}

int ItemSearch::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_itemList.size();
}

QVariant ItemSearch::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_itemList.size())
        return QVariant();

    ItemInfo *item = m_itemList.at(index.row());

    switch (role) {
    case Qt::DisplayRole:
    case Qt::UserRole:
        return item->itemName();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> ItemSearch::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::DisplayRole] = "itemName";
    roles[Qt::UserRole] = "itemName";
    return roles;
}

void ItemSearch::searchItems(const QString &name)
{
    if (!name.isEmpty()) {
        if (m_reply) {
            m_reply->abort();
            m_reply->deleteLater();
            m_reply = nullptr;
        }

        setIsSearching(true);

        QUrl url(QString("https://%1.myshopify.com/products.json").arg(name));
        QNetworkRequest request(url);
        m_reply = m_networkManager.get(request);

        connect(m_reply, &QNetworkReply::finished, this, &ItemSearch::parseData);
    }
}

void ItemSearch::parseData()
{
    if (!m_reply)
        return;

    QByteArray data = m_reply->readAll();

    QFile file("gymshark_raw.json");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(data);
        file.close();
        qDebug() << "Saved JSON to gymshark_raw.json";
    } else {
        qWarning() << "Failed to save JSON to file.";
    }

    m_reply->deleteLater();
    m_reply = nullptr;
    setIsSearching(false);
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

void ItemSearch::loadFromFile(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Failed to open file:" << filePath;
        return;
    }

    QByteArray rawData = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(rawData);
    if (!doc.isObject()) {
        qWarning() << "Invalid JSON structure";
        return;
    }

    QJsonObject root = doc.object();
    QJsonArray products = root["products"].toArray();

    beginResetModel();
    qDeleteAll(m_itemList);
    m_itemList.clear();

    for (const QJsonValue &value : products) {
        QJsonObject obj = value.toObject();
        ItemInfo *item = new ItemInfo(this);

        item->setItemName(obj["title"].toString());
        item->setItemId(QString::number(obj["id"].toVariant().toLongLong()));
        item->setDescription(obj["body_html"].toString());
        item->setProductType(obj["product_type"].toString());
        item->setCreatedAt(obj["created_at"].toString());
        item->setSellerName("Gymshark");

        QJsonArray tagsArray = obj["tags"].toArray();
        QStringList tagList;
        for (const QJsonValue &t : tagsArray)
            tagList.append(t.toString());
        item->setTags(tagList);

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

        QJsonArray images = obj["images"].toArray();
        QList<QUrl> imageUrls;
        for (const QJsonValue &imgVal : images) {
            QJsonObject img = imgVal.toObject();
            imageUrls.append(QUrl(img["src"].toString()));
        }
        item->setImageGallery(imageUrls);

        m_itemList << item;
    }

    endResetModel();
    qDebug() << "Loaded" << m_itemList.size() << "items from" << filePath;

}
