#pragma once
#include "shape.h"
#include <exception>
#include <cmath>

class TwoDimShape : public Shape {
	public:
		TwoDimShape() = default;
		virtual double getSquare() = 0;
		virtual void printPoints() const;
		virtual void scaleX(int x) override;
		virtual void scaleY(int y) override;
		virtual void scaleZ(int z) override;
		virtual void scale(int s) override;
		virtual void shift(int m, int n);
		virtual ~TwoDimShape() = default;
	protected:
		std::vector<Point2D> points;
};