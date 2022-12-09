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
        std::cout << "Created\n";
    } catch(std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }

    try {
        RightTriangle riTri1(10, 20, 30, 30, 60, 90);
        std::cout << "Created\n";

        RightTriangle riTri2(10, 20, 30, 40, 60, 80);
        std::cout << "Created\n";
    } catch(std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }

    try {
        IsosTriangle  isosTri(1, 20, 10, 50, 80, 50);
        std::cout << "Created\n";
    } catch(std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }

    try {
        EquilTriangle equTri(20, 20, 20, 60, 60, 61);
        std::cout << "Created\n";
    } catch(std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }

    try {
        Quadrilateral qua(10, 20, 30, 40, 50, 60, 70, 80);
        std::cout << "Created\n";
    } catch(std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
    
    try {
        Rectangle rec(10, 20, 10, 20, 80, 100, 90, 90);
        std::cout << "Created\n";
    } catch(std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }

    try {
       Square squ(10, 20, 10, 20, 80, 100, 90, 90);
       std::cout << "Created\n";
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
    try {
        Parallelogram par(10, 20, 10, 20, 90, 90, 90, 90);
        std::cout << "Created\n";
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
    try {
        Rhombus rom(10, 20, 10, 20, 90, 90, 90, 90);
        std::cout << "Created\n";
    } catch(std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}