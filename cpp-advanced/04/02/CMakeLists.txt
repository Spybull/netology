cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(advanced_04)
add_executable(catch2_02 main.cc)

find_package(Catch2 3 REQUIRED)
target_link_libraries(catch2_02 PRIVATE Catch2::Catch2)