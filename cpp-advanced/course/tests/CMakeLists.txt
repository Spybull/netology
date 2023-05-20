cmake_minimum_required(VERSION 3.25)
project(course_tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1
)

FetchContent_MakeAvailable(Catch2)

include_directories(../include)
file(GLOB HEADERS ../include/*.hh)
file(GLOB SOURCES ../src/*.cc)
add_executable(test_parser checkIni.cpp ${SOURCES} ${HEADERS})
target_link_libraries(test_parser PRIVATE Catch2::Catch2WithMain)