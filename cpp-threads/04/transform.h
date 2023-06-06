#pragma once
#include "shape.h"
#include <memory>


// class transform
// {
// 	public:
// 		transform(const Shape& sh);
// 		Shape shift(int m, int n, int k);
// 		Shape scaleX(int a);
// 		Shape scaleY(int d);
// 		Shape scaleZ(int e);
// 		Shape scale(int s);

// 	private:
// 		Shape shape;
// };

template<typename T>
class Transform
{
	private:
		std::shared_ptr<T> base;

	public:
		Transform(T *ptr) : base(ptr) {}
		void shift(int m, int n, int k) {};
		Shape *scaleX(int x)
		{
			if (dynamic_cast<TwoDimShape>(base.get()))
		}
};