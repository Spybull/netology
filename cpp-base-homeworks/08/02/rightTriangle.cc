#include "inc/rightTriangle.h"

RightTriangle::RightTriangle(int a, int b, int c, int A, int B, int C)
    : Triangle(a, b, c, A, B, C, "Right Triangle")
{
    if ( C != 90 )
        throw FigureException(FigureExitCodes::ANGLE_C_NOT_90);
}