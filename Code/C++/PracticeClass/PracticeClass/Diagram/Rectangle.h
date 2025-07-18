#pragma once
class Rectangle
{
public:
	Rectangle();
	Rectangle(int _x, int _y);
	~Rectangle();

	int GetArea() const;	// 면적
	int GetGirth() const;	// 둘레

private:
	int x = 0;
	int y = 0;
};

