#include "twoDimShape.h"

void TwoDimShape::printPoints() const {
    for(int i = 0; i < points.size(); ++i) {
        std::cout << "x" << i+1 << ": " << points[i].x << " ";
        std::cout << "y" << i+1 << ": " << points[i].y << " ";
    }
    std::cout << std::endl;
}

void TwoDimShape::scaleX(int x) {
    for (int i = 0; i < points.size(); ++i)
        points[i].x *= x;
}

void TwoDimShape::scaleY(int y) {
    for (int i = 0; i < points.size(); ++i)
        points[i].y *= y;
}

void TwoDimShape::scaleZ(int z) {}

void TwoDimShape::scale(int s) {
    for (int i = 0; i < points.size(); ++i)
    {
        points[i].x /= s;
        points[i].y /= s;
    }
}

void TwoDimShape::shift(int m, int n) {
    for (int i = 0; i < points.size(); ++i)
    {
        points[i].x += m;
        points[i].y += n;
    }
}