#pragma once

// �迭���� � ������� �ľ��� ���� �ϱ� ���� enum
enum calculation
{
	ADD,		// ����
	SUBSTRACT,	// ����
	MULTIPLY,	// ����
	DIVIDE		// ������
};

class Calculator
{
public:
	Calculator();
	~Calculator();

	// ��Ģ����
	int Add(int _x, int _y);
	int Substract(int _x, int _y);
	int Multiply(int _x, int _y);
	float Divide(int _x, int _y);

	// ��� ��� �����ֱ�
	void ShowOperationCount();

private:
	int x = 0;
	int y = 0;

	int arr[4];	// ��� Ƚ�� ������ int �� �迭
};

