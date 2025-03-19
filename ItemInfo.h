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

    Q_PROPERTY(int itemIndex READ itemIndex WRITE setItemIndex NOTIFY itemIndexChanged FINAL)
    Q_PROPERTY(QString itemName READ itemName WRITE setItemName NOTIFY itemNameChanged FINAL)
    Q_PROPERTY(QString sellerName READ sellerName WRITE setSellerName NOTIFY sellerNameChanged FINAL)
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

signals:
    void itemIndexChanged();
    void itemNameChanged();

    void sellerNameChanged();

    void imageSourceChanged();

    void videoSourceChanged();

    void gifSourceChanged();

private:
    int m_itemIndex;
    QString m_itemName;
    QString m_sellerName;
    QUrl m_imageSource;
    QUrl m_videoSource;
    QUrl m_gifSource;
};

#endif // ITEMINFOH_H
