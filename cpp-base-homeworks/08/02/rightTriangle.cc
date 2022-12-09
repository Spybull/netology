#include "rightTriangle.h"

RightTriangle::RightTriangle(int a, int b, int c, int A, int B, int C)
    : Triangle(a, b, c, A, B, C, "RightTriangle")
{
    if ( C != 90 )
        throw FigureException("Can't create! Because: 'C'-angle doesn't equal 90");
}