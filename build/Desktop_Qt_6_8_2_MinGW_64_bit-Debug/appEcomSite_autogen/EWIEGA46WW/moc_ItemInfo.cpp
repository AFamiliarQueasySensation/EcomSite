/****************************************************************************
** Meta object code from reading C++ file 'ItemInfo.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../ItemInfo.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ItemInfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN8ItemInfoE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN8ItemInfoE = QtMocHelpers::stringData(
    "ItemInfo",
    "QML.Element",
    "auto",
    "itemIndexChanged",
    "",
    "itemNameChanged",
    "sellerNameChanged",
    "imageSourceChanged",
    "videoSourceChanged",
    "gifSourceChanged",
    "itemIdChanged",
    "descriptionChanged",
    "productTypeChanged",
    "createdAtChanged",
    "tagsChanged",
    "sizesChanged",
    "pricesChanged",
    "imageGalleryChanged",
    "itemIndex",
    "itemName",
    "itemId",
    "description",
    "productType",
    "createdAt",
    "tags",
    "sizes",
    "prices",
    "imageGallery",
    "QList<QUrl>",
    "sellerName",
    "imageSource",
    "videoSource",
    "gifSource"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN8ItemInfoE[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
      14,   16, // methods
      14,  114, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  100,    4, 0x06,   15 /* Public */,
       5,    0,  101,    4, 0x06,   16 /* Public */,
       6,    0,  102,    4, 0x06,   17 /* Public */,
       7,    0,  103,    4, 0x06,   18 /* Public */,
       8,    0,  104,    4, 0x06,   19 /* Public */,
       9,    0,  105,    4, 0x06,   20 /* Public */,
      10,    0,  106,    4, 0x06,   21 /* Public */,
      11,    0,  107,    4, 0x06,   22 /* Public */,
      12,    0,  108,    4, 0x06,   23 /* Public */,
      13,    0,  109,    4, 0x06,   24 /* Public */,
      14,    0,  110,    4, 0x06,   25 /* Public */,
      15,    0,  111,    4, 0x06,   26 /* Public */,
      16,    0,  112,    4, 0x06,   27 /* Public */,
      17,    0,  113,    4, 0x06,   28 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags, notifyId, revision
      18, QMetaType::Int, 0x00015903, uint(0), 0,
      19, QMetaType::QString, 0x00015903, uint(1), 0,
      20, QMetaType::QString, 0x00015903, uint(6), 0,
      21, QMetaType::QString, 0x00015903, uint(7), 0,
      22, QMetaType::QString, 0x00015903, uint(8), 0,
      23, QMetaType::QString, 0x00015903, uint(9), 0,
      24, QMetaType::QStringList, 0x00015903, uint(10), 0,
      25, QMetaType::QStringList, 0x00015903, uint(11), 0,
      26, QMetaType::QStringList, 0x00015903, uint(12), 0,
      27, 0x80000000 | 28, 0x0001590b, uint(13), 0,
      29, QMetaType::QString, 0x00015903, uint(2), 0,
      30, QMetaType::QUrl, 0x00015903, uint(3), 0,
      31, QMetaType::QUrl, 0x00015903, uint(4), 0,
      32, QMetaType::QUrl, 0x00015903, uint(5), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject ItemInfo::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN8ItemInfoE.offsetsAndSizes,
    qt_meta_data_ZN8ItemInfoE,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'itemIndex'
        int,
        // property 'itemName'
        QString,
        // property 'itemId'
        QString,
        // property 'description'
        QString,
        // property 'productType'
        QString,
        // property 'createdAt'
        QString,
        // property 'tags'
        QStringList,
        // property 'sizes'
        QStringList,
        // property 'prices'
        QStringList,
        // property 'imageGallery'
        QList<QUrl>,
        // property 'sellerName'
        QString,
        // property 'imageSource'
        QUrl,
        // property 'videoSource'
        QUrl,
        // property 'gifSource'
        QUrl,
        // Q_OBJECT / Q_GADGET
        ItemInfo,
        // method 'itemIndexChanged'
        void,
        // method 'itemNameChanged'
        void,
        // method 'sellerNameChanged'
        void,
        // method 'imageSourceChanged'
        void,
        // method 'videoSourceChanged'
        void,
        // method 'gifSourceChanged'
        void,
        // method 'itemIdChanged'
        void,
        // method 'descriptionChanged'
        void,
        // method 'productTypeChanged'
        void,
        // method 'createdAtChanged'
        void,
        // method 'tagsChanged'
        void,
        // method 'sizesChanged'
        void,
        // method 'pricesChanged'
        void,
        // method 'imageGalleryChanged'
        void
    >,
    nullptr
} };

void ItemInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ItemInfo *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->itemIndexChanged(); break;
        case 1: _t->itemNameChanged(); break;
        case 2: _t->sellerNameChanged(); break;
        case 3: _t->imageSourceChanged(); break;
        case 4: _t->videoSourceChanged(); break;
        case 5: _t->gifSourceChanged(); break;
        case 6: _t->itemIdChanged(); break;
        case 7: _t->descriptionChanged(); break;
        case 8: _t->productTypeChanged(); break;
        case 9: _t->createdAtChanged(); break;
        case 10: _t->tagsChanged(); break;
        case 11: _t->sizesChanged(); break;
        case 12: _t->pricesChanged(); break;
        case 13: _t->imageGalleryChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (ItemInfo::*)();
            if (_q_method_type _q_method = &ItemInfo::itemIndexChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (ItemInfo::*)();
            if (_q_method_type _q_method = &ItemInfo::itemNameChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (ItemInfo::*)();
            if (_q_method_type _q_method = &ItemInfo::sellerNameChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (ItemInfo::*)();
            if (_q_method_type _q_method = &ItemInfo::imageSourceChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (ItemInfo::*)();
            if (_q_method_type _q_method = &ItemInfo::videoSourceChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _q_method_type = void (ItemInfo::*)();
            if (_q_method_type _q_method = &ItemInfo::gifSourceChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _q_method_type = void (ItemInfo::*)();
            if (_q_method_type _q_method = &ItemInfo::itemIdChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _q_method_type = void (ItemInfo::*)();
            if (_q_method_type _q_method = &ItemInfo::descriptionChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _q_method_type = void (ItemInfo::*)();
            if (_q_method_type _q_method = &ItemInfo::productTypeChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _q_method_type = void (ItemInfo::*)();
            if (_q_method_type _q_method = &ItemInfo::createdAtChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _q_method_type = void (ItemInfo::*)();
            if (_q_method_type _q_method = &ItemInfo::tagsChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _q_method_type = void (ItemInfo::*)();
            if (_q_method_type _q_method = &ItemInfo::sizesChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _q_method_type = void (ItemInfo::*)();
            if (_q_method_type _q_method = &ItemInfo::pricesChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _q_method_type = void (ItemInfo::*)();
            if (_q_method_type _q_method = &ItemInfo::imageGalleryChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QUrl> >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->itemIndex(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->itemName(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->itemId(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->description(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->productType(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->createdAt(); break;
        case 6: *reinterpret_cast< QStringList*>(_v) = _t->tags(); break;
        case 7: *reinterpret_cast< QStringList*>(_v) = _t->sizes(); break;
        case 8: *reinterpret_cast< QStringList*>(_v) = _t->prices(); break;
        case 9: *reinterpret_cast< QList<QUrl>*>(_v) = _t->imageGallery(); break;
        case 10: *reinterpret_cast< QString*>(_v) = _t->sellerName(); break;
        case 11: *reinterpret_cast< QUrl*>(_v) = _t->imageSource(); break;
        case 12: *reinterpret_cast< QUrl*>(_v) = _t->videoSource(); break;
        case 13: *reinterpret_cast< QUrl*>(_v) = _t->gifSource(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setItemIndex(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setItemName(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setItemId(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setDescription(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setProductType(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setCreatedAt(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setTags(*reinterpret_cast< QStringList*>(_v)); break;
        case 7: _t->setSizes(*reinterpret_cast< QStringList*>(_v)); break;
        case 8: _t->setPrices(*reinterpret_cast< QStringList*>(_v)); break;
        case 9: _t->setImageGallery(*reinterpret_cast< QList<QUrl>*>(_v)); break;
        case 10: _t->setSellerName(*reinterpret_cast< QString*>(_v)); break;
        case 11: _t->setImageSource(*reinterpret_cast< QUrl*>(_v)); break;
        case 12: _t->setVideoSource(*reinterpret_cast< QUrl*>(_v)); break;
        case 13: _t->setGifSource(*reinterpret_cast< QUrl*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *ItemInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ItemInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN8ItemInfoE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ItemInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void ItemInfo::itemIndexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ItemInfo::itemNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ItemInfo::sellerNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ItemInfo::imageSourceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ItemInfo::videoSourceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ItemInfo::gifSourceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ItemInfo::itemIdChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void ItemInfo::descriptionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void ItemInfo::productTypeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void ItemInfo::createdAtChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void ItemInfo::tagsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void ItemInfo::sizesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void ItemInfo::pricesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void ItemInfo::imageGalleryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}
QT_WARNING_POP
