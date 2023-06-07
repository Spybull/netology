#include "square.h"

Square::Square(const std::vector<Point2D> &p)
{
	if (p.size() != 4)
		throw std::invalid_argument("Square must have exactly 4 points" + std::to_string(points.size()));

	points = p;

	for(int i = 0; i < 2; ++i)
	{
		double dx = points[i + 1].x - points[i].x;
		double dy = points[i + 1].y - points[i].y;
		sides[i] = sqrt(dx * dx + dy * dy);
	}
}

std::vector<Point2D> Square::getPoints() const {
	return points;
}

double Square::getSquare()
{
	return sides[0] * sides[1];
}