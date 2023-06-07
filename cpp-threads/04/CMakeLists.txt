cmake_minimum_required(VERSION 3.26)
project(refactoring)

set(CMAKE_CXX_STANDARD 17)
include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCES 
    src/line.cc
    src/circle.cc
    src/square.cc
    src/threeDimShape.cc
    src/twoDimShape.cc
)

add_library(shapelib ${SOURCES})
add_executable(refactoring main.cc)
target_link_libraries(refactoring shapelib)