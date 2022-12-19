cmake_minimum_required(VERSION 3.16.3)
project(my_second_cmake_project)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# ls -1 *.cc
set (SRC_LIST
    equilTriangle.cc
    figure.cc
    isosTriangle.cc
    main.cc
    parallelogram.cc
    quadrilateral.cc
    rectangle.cc
    rhombus.cc
    rightTriangle.cc
    square.cc
    triangle.cc
)

# ls -1 *.h
set (HDR_LIST
    equilTriangle.h
    figure.h
    isosTriangle.h
    parallelogram.h
    quadrilateral.h
    rectangle.h
    rhombus.h
    rightTriangle.h
    square.h
    triangle.h
)

add_executable(a.out "${SRC_LIST}" "${HDR_LIST}")