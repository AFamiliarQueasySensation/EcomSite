#include "ItemController.h"
#include "ItemInfo.h"
#include <QDebug>
#include <QDir>


ItemController::ItemController(QObject *parent)
    : QAbstractListModel{parent}
{
    //Defaulting this to be in the shopping cart

    addItem("Testin1",
            "Testing1",
            QUrl("qrc:assets/images/GreenPush1P.png").path(QUrl::FullyDecoded));
    addItem("Testin2",
            "Testing2",
            QUrl("qrc:assets/images/GreenPush1P.png").path(QUrl::FullyDecoded));
    addItem("Testin3",
            "Testing3",
            QUrl("qrc:assets/images/GreenPush1P.png").path(QUrl::FullyDecoded),
            QUrl("qrc:assets/images/BlueKidnapped.gif").path(QUrl::FullyDecoded));

}

/**
 *
 * We dont really need this because not implementing a tree
 * (gets childrens n stuff)
 * @brief ItemController::rowCount
 * @param parent
 * @return
 */
int ItemController::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_itemInfoList.length();

}

QVariant ItemController::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && index.row() >= 0 && index.row() < m_itemInfoList.length()) {
        ItemInfo* itemInfo = m_itemInfoList[index.row()];

        switch ((Role) role){

        case itemTitleRole:
            return itemInfo->itemName();
        case itemSellerRole:
            return itemInfo->sellerName();
        case itemImageSourceRole:
            return itemInfo->imageSource();
        case itemGifSourceRole:
            return itemInfo->gifSource();
        case itemVideoSourceRole:
            return itemInfo->videoSource();

        }
    }
    return {};
}

QHash<int, QByteArray> ItemController::roleNames() const
{
    QHash<int, QByteArray> result;

    result[itemTitleRole] = "itemTitle";
    result[itemSellerRole] = "itemSeller";
    result[itemImageSourceRole] = "itemImageSource";
    result[itemGifSourceRole] = "itemGifSource";
    result[itemVideoSourceRole] = "itemVideoSource";

    return result;
}

/**
 * Switch to previous item implementation
 * @brief ItemController::switchToPreviousSong
 */
void ItemController::switchToPreviousItem()
{
    const int index = m_itemInfoList.indexOf(m_currentItem);
    if ( index > 0 )
    {
        setCurrentItem(m_itemInfoList[index - 1]);
    } else {
        setCurrentItem(m_itemInfoList.last());
    }

}

/**
 * Switch to next item implementation
 * @brief ItemController::switchToNextSong
 */
void ItemController::switchToNextItem()
{

    const int index = m_itemInfoList.indexOf(m_currentItem);
    if ( index + 1 >= m_itemInfoList.length() )
    {
        setCurrentItem(m_itemInfoList.first());
    } else {
        setCurrentItem(m_itemInfoList[index + 1]);
    }
}

void ItemController::addItem(const QString &title, const QString &sellerName, const QUrl &imageSource, const QUrl &gifSource, const QUrl &videoSource)
{
    beginInsertRows(QModelIndex(), m_itemInfoList.length(), m_itemInfoList.length());


    ItemInfo *itemInfo = new ItemInfo(this);
    itemInfo->setItemName(title);
    itemInfo->setSellerName(sellerName);
    itemInfo->setImageSource(imageSource);
    itemInfo->setGifSource(gifSource);
    itemInfo->setVideoSource(videoSource);

    if (m_itemInfoList.isEmpty()){
        setCurrentItem(itemInfo);
    }

    m_itemInfoList.append(itemInfo);

    endInsertRows();

}

void ItemController::removeItem(int index)
{
    if (index >= 0 && index < m_itemInfoList.length())
    {
        beginRemoveRows(QModelIndex(), index, index);
        ItemInfo *itemRemove = m_itemInfoList[index];

        if (itemRemove == m_currentItem){
            if (m_itemInfoList.length() > 1) {
                if (index != 0) {
                    setCurrentItem(m_itemInfoList[index - 1]);
                } else {
                    setCurrentItem(m_itemInfoList[1]);
                }
            } else {
                setCurrentItem(nullptr);
            }
        }


        m_itemInfoList.removeAt(index);
        itemRemove->deleteLater();
        endRemoveRows();
    }
}

void ItemController::switchToItemByIndex(int index)
{
    if (index >= 0 && index < m_itemInfoList.length()){
        setCurrentItem(m_itemInfoList[index]);
    }
}

ItemInfo *ItemController::currentItem() const
{
    return m_currentItem;
}

void ItemController::setCurrentItem(ItemInfo *newCurrentItem)
{
    if (m_currentItem == newCurrentItem)
        return;
    m_currentItem = newCurrentItem;
    emit currentChangedItem();

}
