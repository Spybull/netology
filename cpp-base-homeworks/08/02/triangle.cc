#include "inc/triangle.h"

Triangle::Triangle(int a, int b, int c, int A, int B, int C)
    : Triangle(a, b, c, A, B, C, "Triangle") {}

Triangle::Triangle(int a, int b, int c, int A, int B, int C, std::string name)
    : Figure(3, name)
    , sides {a, b, c}
    , angles{A, B, C}
{
    this->printInfo();
    if ( (A + B + C) != 180 )
        throw FigureException(FigureExitCodes::ANGLES_SUM_NOT_EQ_180);
}

void Triangle::printInfo() {

    std::cout << "(sides ";
    getSides();
    std::cout << ";";
    std::cout << " angles ";
    getAngles();
    std::cout << ") ";
}    

void Triangle::getSides()
{
    std::cout << sides[0] << ", "
              << sides[1] << ", "
              << sides[2];
}

void Triangle::getAngles()
{
    std::cout << angles[0] << ", "
              << angles[1] << ", "
              << angles[2];
}