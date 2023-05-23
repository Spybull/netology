cmake_minimum_required(VERSION 3.26)
project(threads01)
add_compile_options(-Wall -Wextra -pedantic -O3)
add_executable(threads01 main.cc)
target_compile_features(threads01 PRIVATE cxx_std_17)

