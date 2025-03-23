#include "ItemInfo.h"

ItemInfo::ItemInfo(QObject *parent)
    : QObject(parent)
{
}

// Item Name
QString ItemInfo::itemName() const { return m_itemName; }
void ItemInfo::setItemName(const QString &newItemName) {
    if (m_itemName == newItemName) return;
    m_itemName = newItemName;
    emit itemNameChanged();
}

// Item ID
QString ItemInfo::itemId() const { return m_itemId; }
void ItemInfo::setItemId(const QString &newItemId) {
    if (m_itemId == newItemId) return;
    m_itemId = newItemId;
    emit itemIdChanged();
}

// Description
QString ItemInfo::description() const { return m_description; }
void ItemInfo::setDescription(const QString &newDescription) {
    if (m_description == newDescription) return;
    m_description = newDescription;
    emit descriptionChanged();
}

// Product Type
QString ItemInfo::productType() const { return m_productType; }
void ItemInfo::setProductType(const QString &newProductType) {
    if (m_productType == newProductType) return;
    m_productType = newProductType;
    emit productTypeChanged();
}

// Created At
QString ItemInfo::createdAt() const { return m_createdAt; }
void ItemInfo::setCreatedAt(const QString &newCreatedAt) {
    if (m_createdAt == newCreatedAt) return;
    m_createdAt = newCreatedAt;
    emit createdAtChanged();
}

// Tags
QStringList ItemInfo::tags() const { return m_tags; }
void ItemInfo::setTags(const QStringList &newTags) {
    if (m_tags == newTags) return;
    m_tags = newTags;
    emit tagsChanged();
}

// Sizes
QStringList ItemInfo::sizes() const { return m_sizes; }
void ItemInfo::setSizes(const QStringList &newSizes) {
    if (m_sizes == newSizes) return;
    m_sizes = newSizes;
    emit sizesChanged();
}

// Prices
QStringList ItemInfo::prices() const { return m_prices; }
void ItemInfo::setPrices(const QStringList &newPrices) {
    if (m_prices == newPrices) return;
    m_prices = newPrices;
    emit pricesChanged();
}

// Image Gallery
QList<QUrl> ItemInfo::imageGallery() const { return m_imageGallery; }
void ItemInfo::setImageGallery(const QList<QUrl> &newGallery) {
    if (m_imageGallery == newGallery) return;
    m_imageGallery = newGallery;
    emit imageGalleryChanged();
}

// Seller Name
QString ItemInfo::sellerName() const { return m_sellerName; }
void ItemInfo::setSellerName(const QString &newSellerName) {
    if (m_sellerName == newSellerName) return;
    m_sellerName = newSellerName;
    emit sellerNameChanged();
}
