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
