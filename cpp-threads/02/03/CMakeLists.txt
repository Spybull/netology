cmake_minimum_required(VERSION 3.25)
project(threads03)
add_executable(threads03 main.cc)
target_compile_features(threads03 PRIVATE cxx_std_17)