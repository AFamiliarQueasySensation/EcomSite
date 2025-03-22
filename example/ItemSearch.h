#ifndef ITEMSEARCH_H
#define ITEMSEARCH_H

#include <QAbstractListModel>
#include <QNetworkAccessManager>

class ItemInfo;

class ItemSearch : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(bool isSearching READ isSearching NOTIFY isSearchingChanged)

public:
    enum Role {
        ItemNameRole = Qt::UserRole + 1,
        ItemAuthorRole,
        ItemImageSourceRole,
        ItemSourceRole,
        ItemVideoSourceRole
    };



    explicit ItemSearch(QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;
    bool isSearching() const;
    void setIsSearching(bool newIsSearching);

public slots:
    void searchItems(const QString &name);
    void parseData();

signals:
    void isSearchingChanged();

private:
    QList<ItemInfo*> m_itemList;
    QNetworkAccessManager m_networkManager;
    QNetworkReply *m_reply = nullptr;






    bool m_isSearching;
};

#endif // ITEMSEARCH_H
