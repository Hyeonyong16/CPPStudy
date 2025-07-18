#pragma once

// 배열에서 어떤 계산인지 파악이 쉽게 하기 위한 enum
enum calculation
{
	ADD,		// 덧셈
	SUBSTRACT,	// 뺄셈
	MULTIPLY,	// 곱셈
	DIVIDE		// 나눗셈
};

class Calculator
{
public:
	Calculator();
	~Calculator();

	// 사칙연산
	int Add(int _x, int _y);
	int Substract(int _x, int _y);
	int Multiply(int _x, int _y);
	float Divide(int _x, int _y);

	// 계산 결과 보여주기
	void ShowOperationCount();

private:
	int x = 0;
	int y = 0;

	int arr[4];	// 계산 횟수 저장할 int 형 배열
};

