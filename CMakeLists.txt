cmake_minimum_required(VERSION 3.5)

project(RecipeManager)

set(CMAKE_CXX_STANDARD 14)

find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(SOURCES
    main.cpp
    Recipe.cpp
    RecipeManager.cpp
    MainWindow.cpp
)

set(HEADERS
    Recipe.h
    RecipeManager.h
    MainWindow.h
)

set(UIS
    MainWindow.ui
)

add_executable(RecipeManager ${SOURCES} ${HEADERS} ${UIS})
target_link_libraries(RecipeManager Qt5::Widgets)
