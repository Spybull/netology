#include "inc/rhombus.h"

Rhombus::Rhombus(int a, int b, int c, int d, int A, int B, int C, int D)
    : Quadrilateral(a, b, c, d, A, B, C, D, "Rhombus")
{
    if (a != b || a != c || a != d || b != c || b != d || c != d)
        throw FigureException(FigureExitCodes::ALL_SIDES_NOT_EQ);

    if ( A != C )
        throw FigureException(FigureExitCodes::ANGLES_A_C_NOT_EQUAL);

     if ( B != D )
        throw FigureException(FigureExitCodes::ANGLES_B_D_NOT_EQUAL);
}