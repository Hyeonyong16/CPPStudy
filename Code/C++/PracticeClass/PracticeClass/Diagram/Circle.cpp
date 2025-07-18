#include "Circle.h"
#define PI 3.14159265359

Circle::Circle()
	: radius(0)
{
}

Circle::Circle(int _radius)
	: radius(_radius)
{
}

Circle::~Circle()
{
}

float Circle::GetArea() const
{
	return (float)radius * (float)radius * PI;
}

float Circle::GetGirth() const
{
	return (float)radius * 2.f * PI;
}