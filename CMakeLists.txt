cmake_minimum_required(VERSION 3.1)
project(EcomSite LANGUAGES CXX)

if (ANDROID)
    message(FATAL_ERROR "We dont support android")
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.8.2/mingw_64/lib/cmake")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network WebSockets Concurrent Core5Compat)


add_executable(EcomSite 


    src/main.cpp
    src/webserver.cpp
    src/handleClient.cpp
    src/webserver.h
    src/handleClient.h
    encrypt/encrypt.h
    encrypt/encrypt.cpp
    src/httpsServer.cpp
    src/httpsServer.h
    

    
    )

set_target_properties(EcomSite PROPERTIES
WIN32_EXECUTABLE FALSE
MACOSX_BUNDLE FALSE
)
link_libraries(openssl-3.4.1/include/openssl)

target_link_libraries(EcomSite PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Network Qt6::WebSockets Qt6::Concurrent Qt6::Core5Compat)

