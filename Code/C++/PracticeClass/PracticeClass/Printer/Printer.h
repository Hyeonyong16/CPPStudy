#pragma once

// Printer �� �� ���� ��� ����
// 1. ���ڿ��� ����
// 2. ������ ���ڿ� ���
// 2-1. ���ڿ��� �������� �ʾ����� ��Can��t show the string value���̶�� ������ �߻�
class Printer
{
public:
	Printer();
	~Printer();

	void ShowString();						// ���ڿ� ���
	void SetString(const char* _str);		// ���ڿ� ����

private:
	char* str;
};

