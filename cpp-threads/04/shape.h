#pragma once
#include <string>
#include <vector>
#include <variant>

struct Point2D { double x, y; };
struct Point3D { double x, y, z; };


class Drawable
{
	public:
		Drawable();
		~Drawable();
};

class Shape : public Drawable
{
	private:
		int type;

	public:
		Shape() = default;
		Shape(int type, std::vector<int> coords);
		Shape(int type, int _x1, int _y1, double R, double H);
		virtual double getSquare() = 0;
		virtual ~Shape();

	protected:
		double volume;
		double square;
		double height;
		double radius;
};

class TwoDimShape : public Shape {
	public:
		TwoDimShape();
		double getSquare() override;
};

class ThreeDimShape : public Shape {
	public:
		ThreeDimShape();
		double getSquare() override;
		virtual double getVolume() = 0;
};

class Line : public Drawable
{
	private:
		std::vector<Point2D> points;

	public:
		Line(const std::vector<Point2D> &p);
};

class Square : public TwoDimShape
{
	private:
		int sides[2];
		std::vector<Point2D> points;
	
	public:
		Square(const std::vector<Point2D> &p);
		double getSquare() override;;
};

class Circle : public TwoDimShape
{
	private:
		int x, y;
		double radius, height;
	public:
		Circle(const int x, const int y, const double radius, const double height);
		double getSquare() override;
};

class Cube : public ThreeDimShape
{
	private:
		std::vector<Point3D> points;
		double side_len;

	public:
		Cube(const std::vector<Point3D> &p);
		double getSquare() override;
		double getVolume() override;
};

class Cylinder : public ThreeDimShape
{
	private:
		int x, y;
		double radius, height;

	public:
		Cylinder(const int x, const int y, const double radius, const double height);
		double getSquare() override;
		double getVolume() override;
};
