cmake_minimum_required(VERSION 3.25)
project(threads02)
add_executable(threads02 main.cc)
target_compile_features(threads02 PRIVATE cxx_std_17)