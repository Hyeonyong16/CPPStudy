#include "Rectangle.h"
#include "Circle.h"

Rectangle::Rectangle()
	: x(0), y(0)
{
}

Rectangle::Rectangle(int _x, int _y)
	: x(_x), y(_y)
{
}

Rectangle::~Rectangle()
{
}

int Rectangle::GetArea() const
{
	return x * y;
}

int Rectangle::GetGirth() const
{
	return 2 * x + 2 * y;
}
