#include <iostream>
#include "inc/exceptions.h"
#include "inc/figure.h"

#include "inc/triangle.h"
#include "inc/rightTriangle.h"
#include "inc/isosTriangle.h"
#include "inc/equilTriangle.h"

#include "inc/quadrilateral.h"
#include "inc/rectangle.h"
#include "inc/square.h"
#include "inc/parallelogram.h"
#include "inc/rhombus.h"


int main()
{
    try {
        Figure fig(1);
    } catch(std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }

    try {
        Triangle tri(10, 20, 30, 40, 60, 80);
        std::cout << "Created\n";
    } catch(std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }

    try {
        RightTriangle riTri1(10, 20, 30, 30, 60, 90);
        std::cout << "Created\n";
        RightTriangle riTri2(10, 20, 30, 30, 60, 90);
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