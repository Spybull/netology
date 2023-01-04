#include <iostream>
#include "../../06/03/figure.h"
#include "../../06/03/triangle.h"
#include "../../06/03/rightTriangle.h"
#include "../../06/03/isosTriangle.h"
#include "../../06/03/equilTriangle.h"
#include "../../06/03/quadrilateral.h"
#include "../../06/03/rectangle.h"
#include "../../06/03/square.h"
#include "../../06/03/parallelogram.h"
#include "../../06/03/rhombus.h"

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