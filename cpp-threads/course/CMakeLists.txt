cmake_minimum_required(VERSION 3.26 FATAL_ERROR)
project(thread_safe_queue CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)
set(SOURCES 
    src/thread_pool.cc
)

add_executable(thread_safe_queue ${SOURCES} main.cc)