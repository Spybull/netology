cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

project(course)
include_directories(include/air include/ground include)

add_library(course SHARED
    sources/ground/camel.cc
    sources/ground/camelSpeed.cc
    sources/ground/centaur.cc
    sources/ground/ground.cc
    sources/ground/terrainBoots.cc
    sources/air/air.cc
    sources/air/broom.cc
    sources/air/carpetPlane.cc
    sources/air/eagle.cc
    sources/transport.cc
    sources/race.cc
    sources/racepool.cc
)

add_executable(a.out main.cc)
target_link_libraries(a.out course)
