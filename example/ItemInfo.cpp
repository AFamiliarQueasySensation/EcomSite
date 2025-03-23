#include "ItemInfo.h"

ItemInfo::ItemInfo(QObject *parent)
    : QObject{parent}
{}

int ItemInfo::itemIndex() const
{
    return m_itemIndex;
}

void ItemInfo::setItemIndex(int newItemIndex)
{
    if (m_itemIndex == newItemIndex)
        return;
    m_itemIndex = newItemIndex;
    emit itemIndexChanged();
}

QString ItemInfo::itemName() const
{
    return m_itemName;
}

void ItemInfo::setItemName(const QString &newItemName)
{
    if (m_itemName == newItemName)
        return;
    m_itemName = newItemName;
    emit itemNameChanged();
}

QString ItemInfo::sellerName() const
{
    return m_sellerName;
}

void ItemInfo::setSellerName(const QString &newSellerName)
{
    if (m_sellerName == newSellerName)
        return;
    m_sellerName = newSellerName;
    emit sellerNameChanged();
}

QUrl ItemInfo::imageSource() const
{
    return m_imageSource;
}

void ItemInfo::setImageSource(const QUrl &newImageSource)
{
    if (m_imageSource == newImageSource)
        return;
    m_imageSource = newImageSource;
    emit imageSourceChanged();
}

QUrl ItemInfo::videoSource() const
{
    return m_videoSource;
}

void ItemInfo::setVideoSource(const QUrl &newVideoSource)
{
    if (m_videoSource == newVideoSource)
        return;
    m_videoSource = newVideoSource;
    emit videoSourceChanged();
}

QUrl ItemInfo::gifSource() const
{
    return m_gifSource;
}

void ItemInfo::setGifSource(const QUrl &newGifSource)
{
    if (m_gifSource == newGifSource)
        return;
    m_gifSource = newGifSource;
    emit gifSourceChanged();
}

QString ItemInfo::itemId() const
{
    return m_itemId;
}

void ItemInfo::setItemId(const QString &newItemId)
{
    if (m_itemId == newItemId)
        return;
    m_itemId = newItemId;
    emit itemIdChanged();
}

QString ItemInfo::description() const
{
    return m_description;
}

void ItemInfo::setDescription(const QString &newDescription)
{
    if (m_description == newDescription)
        return;
    m_description = newDescription;
    emit descriptionChanged();
}

QString ItemInfo::productType() const
{
    return m_productType;
}

void ItemInfo::setProductType(const QString &newProductType)
{
    if (m_productType == newProductType)
        return;
    m_productType = newProductType;
    emit productTypeChanged();
}

QString ItemInfo::createdAt() const
{
    return m_createdAt;
}

void ItemInfo::setCreatedAt(const QString &newCreatedAt)
{
    if (m_createdAt == newCreatedAt)
        return;
    m_createdAt = newCreatedAt;
    emit createdAtChanged();
}

QStringList ItemInfo::tags() const
{
    return m_tags;
}

void ItemInfo::setTags(const QStringList &newTags)
{
    if (m_tags == newTags)
        return;
    m_tags = newTags;
    emit tagsChanged();
}

QStringList ItemInfo::sizes() const
{
    return m_sizes;
}

void ItemInfo::setSizes(const QStringList &newSizes)
{
    if (m_sizes == newSizes)
        return;
    m_sizes = newSizes;
    emit sizesChanged();
}

QStringList ItemInfo::prices() const
{
    return m_prices;
}

void ItemInfo::setPrices(const QStringList &newPrices)
{
    if (m_prices == newPrices)
        return;
    m_prices = newPrices;
    emit pricesChanged();
}

QList<QUrl> ItemInfo::imageGallery() const
{
    return m_imageGallery;
}

void ItemInfo::setImageGallery(const QList<QUrl> &newImageGallery)
{
    if (m_imageGallery == newImageGallery)
        return;
    m_imageGallery = newImageGallery;
    emit imageGalleryChanged();
}
