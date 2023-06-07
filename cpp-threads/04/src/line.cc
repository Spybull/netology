#include "line.h"

void Line::scaleX(int x) {
    for (int i = 0; i < points.size(); ++i)
        points[i].x *= x;
}

void Line::scaleY(int y) {
    for (int i = 0; i < points.size(); ++i)
        points[i].y *= y;
}

void Line::scale(int s) {
    for (int i = 0; i < points.size(); ++i)
    {
        points[i].x /= s;
        points[i].y /= s;
    }
}

void Line::shift(int m, int n)
{
	for (int i = 0; i < points.size(); ++i)
    {
        points[i].x += m;
        points[i].y += n;
    }
}