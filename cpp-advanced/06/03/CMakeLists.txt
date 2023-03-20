cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(advanced_06)
add_executable(stl main.cc)

find_package(Catch2 3 REQUIRED)
target_link_libraries(stl PRIVATE Catch2::Catch2)