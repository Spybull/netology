cmake_minimum_required(VERSION 3.26)
add_compile_options(-Wall -Wextra -Wpedantic)
add_compile_options(-O3)


project(cpp-threads01)
add_executable(cpp-threads01 main.cc)
target_compile_features(cpp-threads01 PRIVATE cxx_std_17)