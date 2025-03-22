#ifndef ITEMCONTROLLER_H
#define ITEMCONTROLLER_H

#include <QObject>
#include <QAbstractListModel>
#include "ItemInfo.h"

class ItemInfo;

class ItemController : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(ItemInfo* currentItem READ currentItem WRITE setCurrentItem NOTIFY currentChangedItem)


public:
    enum Role {
        itemTitleRole = Qt::UserRole + 1,
        itemSellerRole,
        itemImageSourceRole,
        itemGifSourceRole,
        itemVideoSourceRole

    };


    explicit ItemController(QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;


    ItemInfo* currentItem() const;
    void setCurrentItem(ItemInfo *newCurrentItem);

public slots:

    void switchToPreviousItem();
    void switchToNextItem();
    void addItem(const QString&title, const QString& sellerName, const QUrl& imageSource = QUrl(), const QUrl& gifSource = QUrl(), const QUrl& videoSource = QUrl());
    void removeItem(int index);
    void switchToItemByIndex(int index);

signals:

    void currentChangedItem();

private:
    /*Shopping cart list */
    QList<ItemInfo*> m_itemInfoList;

    /*Current item displayed in shopping cart */
    ItemInfo *m_currentItem;
};

#endif // ITEMCONTROLLER_H
