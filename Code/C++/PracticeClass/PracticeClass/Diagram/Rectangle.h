#pragma once
class Rectangle
{
public:
	Rectangle();
	Rectangle(int _x, int _y);
	~Rectangle();

	int GetArea() const;	// ����
	int GetGirth() const;	// �ѷ�

private:
	int x = 0;
	int y = 0;
};

