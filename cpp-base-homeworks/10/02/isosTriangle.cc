#include "isosTriangle.h"

IsosTriangle::IsosTriangle(int a, int b, int A, int B)
    : Triangle(a, b, a, A, B, A)
{
    name = "Isosceles Triangle";
}