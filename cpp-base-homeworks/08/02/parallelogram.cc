#include "inc/parallelogram.h"
Parallelogram::Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D)
    : Quadrilateral(a, b, c, d, A, B, C, D, "Parallelogram")
{
    if ( a != c )
        throw FigureException(FigureExitCodes::SIDES_A_C_NOT_EQUAL);
    
    if ( b != d )
        throw FigureException(FigureExitCodes::SIDES_B_D_NOT_EQUAL);

     if ( A != C )
        throw FigureException(FigureExitCodes::ANGLES_A_C_NOT_EQUAL);

     if ( B != D )
        throw FigureException(FigureExitCodes::ANGLES_B_D_NOT_EQUAL);
}