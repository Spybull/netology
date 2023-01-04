

cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

project(FourthTask)

add_library(figures SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../06/03/figure.cc
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../06/03/figure.h
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../06/03/equilTriangle.cc
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../06/03/equilTriangle.h
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../06/03/isosTriangle.cc
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../06/03/isosTriangle.h
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../06/03/parallelogram.cc
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../06/03/parallelogram.h
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../06/03/quadrilateral.cc
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../06/03/quadrilateral.h
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../06/03/rectangle.cc
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../06/03/rectangle.h
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../06/03/rhombus.cc
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../06/03/rhombus.h
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../06/03/rightTriangle.cc
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../06/03/rightTriangle.h
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../06/03/square.cc
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../06/03/square.h
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../06/03/triangle.cc
    ${CMAKE_CURRENT_SOURCE_DIR}../../../../06/03/triangle.h
)
