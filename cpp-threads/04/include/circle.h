#pragma once
#include "twoDimShape.h"

class Circle final : public TwoDimShape
{
	private:
		int x, y;
		double radius, height;
	public:
		Circle(const int x, const int y, const double radius, const double height);
		double getSquare() override;
};