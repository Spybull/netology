#include <iostream>
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

void printInfo(Figure *base) { 
    base->printInfo();
}

int main()
{
    Triangle tri(10, 20, 30, 50, 60, 70);
    RightTriangle riTri(10, 20, 30, 50, 60);
    IsosTriangle  isosTri(10, 20, 50, 60);
    EquilTriangle equTri(30);

    printInfo(&tri);
    printInfo(&riTri);
    printInfo(&isosTri);
    printInfo(&equTri);

    Quadrilateral qua(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rec(10, 20);
    Square squ(20);
    Parallelogram par(20, 30, 30, 40);
    Rhombus rom(30, 30, 40);

    printInfo(&qua);
    printInfo(&rec);
    printInfo(&squ);
    printInfo(&par);
    printInfo(&rom);

    return 0;
}