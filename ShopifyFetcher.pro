QT += core network qml

CONFIG += c++17 cmdline

SOURCES += \
    ItemInfo.cpp \
    itemsearch.cpp \
    main.cpp

HEADERS += \
    ItemInfo.h \
    itemsearch.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
