cmake_minimum_required(VERSION 3.26)
add_compile_options(-Wall -Wextra -Wpedantic)
add_compile_options(-O3)

project(SQLCpp05)

add_subdirectory(libpqxx)

set (SOURCES ClientManager.cc parser.cc main.cc)
set(HEADERS ClientManager.h parser.h)

add_executable(SQLCpp05 "${SOURCES}" "${HEADERS}")

target_compile_features(SQLCpp05 PRIVATE cxx_std_17)
target_link_libraries(SQLCpp05 pqxx)