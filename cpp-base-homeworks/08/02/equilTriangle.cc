#include "equilTriangle.h"

EquilTriangle::EquilTriangle(int a, int b, int c, int A, int B, int C)
    : Triangle(a, b, c, A, B, C, "Equilateral Triangle")
{

    if ( a != b || a != c || b != c)
        throw FigureException("Can't create! Because: all sides must be equal");

    if ( A != 60 || B != 60 || C != 60)
        throw FigureException("Can't create! Because: all angles must be 60");
}