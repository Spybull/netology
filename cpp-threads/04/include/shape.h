#pragma once
#include <iostream>
#include <exception>
#include <stdexcept>
#include <iomanip>
#include <limits>
#include <cmath>
#include <numbers>
#include <string>
#include <vector>

struct Point2D { int x; int y; };
struct Point3D { int x; int y; int z; };

class Shape
{
	private:
		int type;

	public:
		virtual double getSquare() = 0;
		virtual void scaleX(int x) = 0;
		virtual void scaleY(int y) = 0;
		virtual void scaleZ(int z) = 0;
		virtual void scale(int s) = 0;
		virtual ~Shape() = default;

	protected:
		double volume;
		double square;
		double height;
		double radius;
};

