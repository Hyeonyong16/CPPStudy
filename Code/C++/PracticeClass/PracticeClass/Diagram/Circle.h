#pragma once

class Circle
{
public:
	Circle();
	Circle(int _radius);
	~Circle();

	float GetArea() const;
	float GetGirth() const;

private:
	int radius;
};

