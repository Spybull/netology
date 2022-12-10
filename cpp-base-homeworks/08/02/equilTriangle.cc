#include "inc/equilTriangle.h"

EquilTriangle::EquilTriangle(int a, int b, int c, int A, int B, int C)
    : Triangle(a, b, c, A, B, C, "Equilateral Triangle")
{

    if ( a != b || a != c || b != c)
        throw FigureException(FigureExitCodes::ALL_SIDES_NOT_EQ);

    if ( A != 60 || B != 60 || C != 60)
        throw FigureException(FigureExitCodes::ALL_ANGLES_NOT_EQ_60);
}