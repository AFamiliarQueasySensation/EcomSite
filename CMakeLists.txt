cmake_minimum_required(VERSION 3.10.0)
project(simple VERSION 0.1.0 LANGUAGES C CXX)

find_package(Qt6 REQUIRED COMPONENTS HttpServer)

include_directories("/opt/homebrew/include")
link_directories("/opt/homebrew/lib")


if(ANDROID)
    find_package(Qt6 REQUIRED COMPONENTS Gui)
endif()

qt_standard_project_setup()


add_executable(simple

    main.cpp
    
)
target_link_libraries(simple PRIVATE
    Qt6::HttpServer
)



