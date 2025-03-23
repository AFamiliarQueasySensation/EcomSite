#ifndef ITEMINFO_H
#define ITEMINFO_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QUrl>
#include <QList>
#include <qqml.h>

class ItemInfo : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString itemName READ itemName WRITE setItemName NOTIFY itemNameChanged FINAL)
    Q_PROPERTY(QString itemId READ itemId WRITE setItemId NOTIFY itemIdChanged FINAL)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged FINAL)
    Q_PROPERTY(QString productType READ productType WRITE setProductType NOTIFY productTypeChanged FINAL)
    Q_PROPERTY(QString createdAt READ createdAt WRITE setCreatedAt NOTIFY createdAtChanged FINAL)
    Q_PROPERTY(QStringList tags READ tags WRITE setTags NOTIFY tagsChanged FINAL)
    Q_PROPERTY(QStringList sizes READ sizes WRITE setSizes NOTIFY sizesChanged FINAL)
    Q_PROPERTY(QStringList prices READ prices WRITE setPrices NOTIFY pricesChanged FINAL)
    Q_PROPERTY(QList<QUrl> imageGallery READ imageGallery WRITE setImageGallery NOTIFY imageGalleryChanged FINAL)
    Q_PROPERTY(QString sellerName READ sellerName WRITE setSellerName NOTIFY sellerNameChanged FINAL)

public:
    explicit ItemInfo(QObject *parent = nullptr);

    QString itemName() const;
    void setItemName(const QString &newItemName);

    QString itemId() const;
    void setItemId(const QString &newItemId);

    QString description() const;
    void setDescription(const QString &newDescription);

    QString productType() const;
    void setProductType(const QString &newProductType);

    QString createdAt() const;
    void setCreatedAt(const QString &newCreatedAt);

    QStringList tags() const;
    void setTags(const QStringList &newTags);

    QStringList sizes() const;
    void setSizes(const QStringList &newSizes);

    QStringList prices() const;
    void setPrices(const QStringList &newPrices);

    QList<QUrl> imageGallery() const;
    void setImageGallery(const QList<QUrl> &newGallery);

    QString sellerName() const;
    void setSellerName(const QString &newSellerName);

signals:
    void itemNameChanged();
    void itemIdChanged();
    void descriptionChanged();
    void productTypeChanged();
    void createdAtChanged();
    void tagsChanged();
    void sizesChanged();
    void pricesChanged();
    void imageGalleryChanged();
    void sellerNameChanged();

private:
    QString m_itemName;
    QString m_itemId;
    QString m_description;
    QString m_productType;
    QString m_createdAt;
    QStringList m_tags;
    QStringList m_sizes;
    QStringList m_prices;
    QList<QUrl> m_imageGallery;
    QString m_sellerName;
};

#endif // ITEMINFO_H
