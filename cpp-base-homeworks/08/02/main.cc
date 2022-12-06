#include <iostream>
#include "exceptions.h"
#include "figure.h"
#include "triangle.h"
#include "rightTriangle.h"
#include "isosTriangle.h"
#include "equilTriangle.h"
#include "quadrilateral.h"
#include "rectangle.h"
#include "square.h"
#include "parallelogram.h"
#include "rhombus.h"

int main()
{
    try {
        Triangle tri(10, 20, 30, 40, 60, 80);
    } catch(std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }

    try {
        RightTriangle riTri1(10, 20, 30, 30, 60);
        RightTriangle riTri2(10, 20, 30, 40, 60);
    } catch(std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }

    try {
        EquilTriangle equTri(30);
        IsosTriangle  isosTri(10, 20, 50, 30);
    } catch(std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }

    try {
        Quadrilateral qua(10, 20, 30, 40, 50, 60, 70, 80);
    } catch(std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
    
    try {
        Rectangle rec(10, 20);
        Square squ(20);
        Parallelogram par(20, 30, 30, 40);
    } catch(std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }

    try {
        Rhombus rom(30, 30, 40);
    } catch(std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}