#include "quadrilateral.h"

Quadrilateral::Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D)
    : Figure(4, "Quadrilateral")
    , sides  {a, b, c, d}
    , angles {A, B, C, D}
    {}

void Quadrilateral::printInfo() {
    Figure::printInfo();

    std::cout << "Sides:\t";
    getSides();

    std::cout << "\nAngles:\t";
    getAngles();

    std::cout << "\n\n";
}

void Quadrilateral::getSides() {
    int i = 0;
    for(char c='a'; c <= 'd'; ++c && ++i)
        std::cout << c << "=" << sides[i] << " ";
}

void Quadrilateral::getAngles() {
    int i = 0;
    for(char c='A'; c <= 'D'; ++c && ++i)
        std::cout << c << "=" << angles[i] << " ";
}