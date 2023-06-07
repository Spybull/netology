#include "threeDimShape.h"

void ThreeDimShape::scaleX(int x) {
    for (int i = 0; i < points.size(); ++i)
        points[i].x *= x;
}

void ThreeDimShape::scaleY(int y) {
    for (int i = 0; i < points.size(); ++i)
        points[i].y *= y;
}

void ThreeDimShape::scaleZ(int z) {
	for (int i = 0; i < points.size(); ++i)
        points[i].z *= z;
}

void ThreeDimShape::scale(int s) {
    for (int i = 0; i < points.size(); ++i)
    {
        points[i].x /= s;
        points[i].y /= s;
		points[i].z /= s;
    }
}

void ThreeDimShape::shift(int m, int n, int k)
{
	for (int i = 0; i < points.size(); ++i)
    {
        points[i].x += m;
        points[i].y += n;
		points[i].z += k;
    }
}

Cube::Cube(const std::vector<Point3D> &p) : points(p) {
	if (points.size() != 8)
		throw std::invalid_argument("Cube must have exactly 8 points");

	double dx = points[1].x - points[0].x,
	 	   dy = points[1].y - points[0].y,
		   dz = points[1].z - points[0].z;
	side_len = sqrt(dx * dx + dy *dy + dz * dz);
}
double Cube::getSquare() { return 6 * std::pow(side_len, 2); }
double Cube::getVolume() { return std::pow(side_len, 3); }

Cylinder::Cylinder(const int x,
				   const int y,
				   const double radius,
				   const double height)
: x(x)
, y(y)
, radius(radius)
, height(height)
{
	square = 3.14 * std::pow(radius, 2) + 2 * radius * height;
	volume = 3.14 * std::pow(radius, 2) * height;
}