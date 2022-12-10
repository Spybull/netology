#include "inc/quadrilateral.h"

Quadrilateral::Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D)
    : Quadrilateral(a, b, c, d, A, B, C, D, "Quadrilateral")
{}

Quadrilateral::Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D, std::string name)
    : Figure(4, name)
    , sides  {a, b, c, d}
    , angles {A, B, C, D}
{
    printInfo();
    if ( (A + B + C + D) != 360 )
        throw FigureException(FigureExitCodes::ANGLES_SUM_NOT_EQ_360);
}

void Quadrilateral::printInfo() {

    std::cout << "(sides ";
    getSides();
    std::cout << ";";
    std::cout << " angles ";
    getAngles();
    std::cout << ") ";
}

void Quadrilateral::getSides() {
    std::cout << sides[0] << ", "
              << sides[1] << ", "
              << sides[2] << ", "
              << sides[3];
}

void Quadrilateral::getAngles() {
    std::cout << angles[0] << ", "
              << angles[1] << ", "
              << angles[2] << ", "
              << angles[3];
}