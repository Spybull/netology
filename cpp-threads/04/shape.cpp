#include "shape.h"
#include <cmath>
#include <iostream>
#include <exception>
#include <iomanip>
#include <limits>
#include <numbers>

Line::Line(const std::vector<Point2D> &p) : points(p) {
	if (points.size() != 2)
		throw std::invalid_argument("Line must have exactly 2 points");
}

Square::Square(const std::vector<Point2D> &p) : points(p) {
	if (points.size() != 4)
		throw std::invalid_argument("Square must have exactly 4 points");

	for(int i = 0; i < 2; ++i)
	{
		double dx = points[i + 1].x - points[i].x;
		double dy = points[i + 1].y - points[i].y;
		sides[i] = sqrt(dx * dx + dy * dy);
	}
}
double Square::getSquare() { return sides[0] * sides[1]; }

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

Circle::Circle(const int x,
			   const int y,
			   const double radius,
			   const double height)
: x(x)
, y(y)
, radius(radius)
, height(height)
{
	square = std::numbers::pi * std::pow(radius, 2);
}
double Circle::getSquare() { return square; }

Cylinder::Cylinder(const int x,
				   const int y,
				   const double radius,
				   const double height)
: x(x)
, y(y)
, radius(radius)
, height(height)
{
	square = std::numbers::pi * std::pow(radius, 2) + 2 * radius * height;
	volume = std::numbers::pi * std::pow(radius, 2) * height;
}