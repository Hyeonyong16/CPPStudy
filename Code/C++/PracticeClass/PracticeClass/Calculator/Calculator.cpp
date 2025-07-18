#include "Calculator.h"
#include <iostream>

Calculator::Calculator()
    : x(0), y(0)
{
    for (int i = 0; i < 4; ++i)
    {
        arr[i] = 0;
    }
}

Calculator::~Calculator()
{
}

int Calculator::Add(int _x, int _y)
{
    ++arr[ADD];
    return _x + _y;
}

int Calculator::Substract(int _x, int _y)
{
    ++arr[SUBSTRACT];
    return _x - _y;
}

int Calculator::Multiply(int _x, int _y)
{
    ++arr[MULTIPLY];
    return _x * _y;
}

float Calculator::Divide(int _x, int _y)
{
    if (_y == 0) return -1;
    ++arr[DIVIDE];
    return (float)_x / (float)_y;
}

void Calculator::ShowOperationCount()
{
    std::cout
        << "����: " << arr[ADD] << "\n"
        << "����: " << arr[SUBSTRACT] << "\n"
        << "����: " << arr[MULTIPLY] << "\n"
        << "������: " << arr[DIVIDE] << "\n";
}
