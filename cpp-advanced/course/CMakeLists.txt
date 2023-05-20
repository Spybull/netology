
cmake_minimum_required(VERSION 3.25)
project(course)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(
    ${CMAKE_SOURCE_DIR}/tests/test.ini
    ${CMAKE_CURRENT_BINARY_DIR}/ COPYONLY
)
configure_file(
    ${CMAKE_SOURCE_DIR}/tests/test_exceptions.ini
    ${CMAKE_CURRENT_BINARY_DIR}/ COPYONLY
)

include_directories(include)
file(GLOB HEADERS "include/*.hh")
file(GLOB SOURCES "src/*.cc")

add_executable(parser main.cc ${SOURCES} ${HEADERS})