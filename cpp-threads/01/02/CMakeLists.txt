cmake_minimum_required(VERSION 3.26)

if(UNIX AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-Wall -Wextra -Wpedantic -O3)
endif()

set(PROGRAM_NAME $ENV{PROGRAM_NAME})
project(${PROGRAM_NAME})

find_package(Threads REQUIRED)
add_executable(${PROGRAM_NAME} main.cc)
target_link_libraries(${PROGRAM_NAME} Threads::Threads)
target_compile_features(${PROGRAM_NAME} PRIVATE cxx_std_17)