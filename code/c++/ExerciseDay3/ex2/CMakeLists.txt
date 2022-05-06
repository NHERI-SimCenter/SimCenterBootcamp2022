cmake_minimum_required (VERSION 2.6)
set (CMAKE_C_STANDARD 99)

project (Shapes)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(ex1 main.cpp Vector.cpp)

