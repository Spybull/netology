cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

project(FifthTask)

add_subdirectory(04)
add_executable(a.out main.cc)
target_link_libraries(a.out figures)