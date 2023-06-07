#pragma once
#include "shape.h"
#include "twoDimShape.h"
#include <stdexcept>

class ThreeDimShape : public Shape {
	public:
		ThreeDimShape() = default;
		virtual double getSquare() = 0;
		virtual double getVolume() = 0;
		virtual void scaleX(int x) override;
		virtual void scaleY(int y) override;
		virtual void scaleZ(int z) override;
		virtual void scale(int s) override;
		virtual void shift(int m, int n, int k);
		virtual ~ThreeDimShape() = default;
	protected:
		std::vector<Point3D> points;
};

class Cube final : public ThreeDimShape
{
	private:
		std::vector<Point3D> points;
		double side_len;

	public:
		Cube(const std::vector<Point3D> &p);
		double getSquare() override;
		double getVolume() override;
};

class Cylinder final : public ThreeDimShape
{
	private:
		int x, y;
		double radius, height;

	public:
		Cylinder(const int x, const int y, const double radius, const double height);
		double getSquare() override;
		double getVolume() override;
};
