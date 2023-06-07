#pragma once
#include "shape.h"

class Line : public Shape
{
	public:
		Line() = default;
		virtual double getSquare() = 0;
        virtual void scaleZ(int z) = 0;
		virtual void scaleX(int x) override;
		virtual void scaleY(int y) override;
		virtual void scale(int s) override;
		virtual void shift(int m, int n);

	protected:
		std::vector<Point2D> points;
};