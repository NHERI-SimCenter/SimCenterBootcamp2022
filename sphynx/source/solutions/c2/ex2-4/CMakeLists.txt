cmake_minimum_required (VERSION 2.6)

project (Exercise2-4)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(Exercise2-4 exercise2-4.c stresstransform.c)
target_link_libraries(Exercise2-4 m)
