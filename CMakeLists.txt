     cmake_minimum_required(VERSION 3.5)

     project(RecipeManager)

     set(CMAKE_CXX_STANDARD 14)

     find_package(Qt5Widgets REQUIRED)

     add_executable(RecipeManager main.cpp Recipe.cpp RecipeManager.cpp MainWindow.cpp)
     target_link_libraries(RecipeManager Qt5::Widgets)
     


