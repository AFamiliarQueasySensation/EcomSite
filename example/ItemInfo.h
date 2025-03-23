#ifndef ITEMINFOH_H
#define ITEMINFOH_H

#include <QObject>
#include <QUrl>
#include <QString>
#include <qqml.h>

class ItemInfo : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(int itemIndex READ itemIndex WRITE setItemIndex NOTIFY itemIndexChanged FINAL) // not sure if we need this
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

    //Using this specifically for the search mechanism since it would only hold a singular image
    Q_PROPERTY(QUrl imageSource READ imageSource WRITE setImageSource NOTIFY imageSourceChanged FINAL)



    Q_PROPERTY(QUrl videoSource READ videoSource WRITE setVideoSource NOTIFY videoSourceChanged FINAL)
    Q_PROPERTY(QUrl gifSource READ gifSource WRITE setGifSource NOTIFY gifSourceChanged FINAL)




public:
    explicit ItemInfo(QObject *parent = nullptr);

    int itemIndex() const;
    void setItemIndex(int newItemIndex);

    QString itemName() const;
    void setItemName(const QString &newItemName);

    QString sellerName() const;
    void setSellerName(const QString &newSellerName);

    QUrl imageSource() const;
    void setImageSource(const QUrl &newImageSource);

    QUrl videoSource() const;
    void setVideoSource(const QUrl &newVideoSource);

    QUrl gifSource() const;
    void setGifSource(const QUrl &newGifSource);

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
    void setImageGallery(const QList<QUrl> &newImageGallery);

signals:

    void itemIndexChanged();

    void itemNameChanged();

    void sellerNameChanged();

    void imageSourceChanged();

    void videoSourceChanged();

    void gifSourceChanged();

    void itemIdChanged();

    void descriptionChanged();

    void productTypeChanged();

    void createdAtChanged();

    void tagsChanged();

    void sizesChanged();

    void pricesChanged();

    void imageGalleryChanged();

private:

    int m_itemIndex;
    QString m_itemName;
    QString m_sellerName;
    QUrl m_imageSource;
    QUrl m_videoSource;
    QUrl m_gifSource;
    QString m_itemId;
    QString m_description;
    QString m_productType;
    QString m_createdAt;
    QStringList m_tags;
    QStringList m_sizes;
    QStringList m_prices;
    QList<QUrl> m_imageGallery;
};

#endif // ITEMINFOH_H
