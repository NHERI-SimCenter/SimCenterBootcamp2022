cmake_minimum_required (VERSION 2.6)
set (CMAKE_C_STANDARD 99)

project (Shapes)

include_directories(${PROJECT_SOURCE_DIR})
add_library(ShapeLib Circle.cpp Rectangle.cpp Shape.cpp Square.cpp)
add_executable(ex1 main1.cpp)
add_executable(ex2 main2.cpp)
add_executable(ex3 main3.cpp)
target_link_libraries (ex1 ShapeLib)
target_link_libraries (ex2 ShapeLib)
target_link_libraries (ex3 ShapeLib) 
