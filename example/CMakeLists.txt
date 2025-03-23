cmake_minimum_required(VERSION 3.16)

project(CS3307 VERSION 0.1 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "C:/Qt/6.8.2/mingw_64/lib/cmake")

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Multimedia Quick)

#qt_standard_project_setup(REQUIRES 6.8)
qt_add_executable(appEcomSite
    main.cpp
    ItemController.cpp
    ItemController.h
    ItemSearch.cpp
    ItemSearch.h
)

qt_add_qml_module(appEcomSite
    URI example
    VERSION 1.0

    QML_FILES
        Main.qml
        ItemInfoBox.qml
        ImageButton.qml
        ShoppingCart.qml
        SearchField.qml
        ItemSearchDisplay.qml

    SOURCES
        ItemInfo.cpp
        ItemInfo.h

    RESOURCES
        assets/images/BlueIdle.gif
        assets/images/BlueKidnapped.gif
        assets/images/GreenPush1P.png

        assets/icons/favicon.ico
        assets/icons/next.png
        assets/icons/Previous.png
        assets/icons/addButton.png
        assets/icons/trashcan.png
        assets/icons/menu_icon.png
        assets/icons/homeIcon.png


)


set_target_properties(appEcomSite PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)


target_link_libraries(appEcomSite
    PRIVATE Qt6::Quick Qt6::Multimedia
)

install(TARGETS appEcomSite
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
