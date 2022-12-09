#include "square.h"

Square::Square(int a, int b, int c, int d, int A, int B, int C, int D)
    : Quadrilateral(a, b, c, d, A, B, C, D, "Square")
{
    if (a != b || a != c || a != d || b != c || b != d || c != d)
        throw FigureException("Can't create! Because: all sides must be equal");

    if ( A != 90 || B != 90 || C != 90 || D != 90)
        throw FigureException("Can't create! Because: all angles must be 90");
}