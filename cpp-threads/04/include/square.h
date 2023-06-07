#pragma once
#include "twoDimShape.h"

class Square final : public TwoDimShape
{
	private:
		int sides[2];
	public:
		Square(const std::vector<Point2D> &p);
		double getSquare() override;
		std::vector<Point2D> getPoints() const;
};