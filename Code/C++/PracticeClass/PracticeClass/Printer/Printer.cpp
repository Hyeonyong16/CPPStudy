#include "Printer.h"

#include <iostream>

Printer::Printer()
    : str(nullptr)
{
}

Printer::~Printer()
{
    if (nullptr != str)
        delete[] str;
}

void Printer::ShowString()
{
    // ���ڿ��� �������� �ʾ��� ��� ����ó��
    if (nullptr == str) { std::cout << "Can��t show the string value\n"; return; }

    // ���ڿ��� �����Ǿ� ������ ���
    std::cout << str << std::endl;

    // ���ڿ� ��� �� ���ڿ� ���� ����(�޸� �Ҵ絵 ����)
    delete[] str;
    str = nullptr;
}

void Printer::SetString(const char* _str)
{
    // �Է¹��� ���ڿ� ����
    size_t length = strlen(_str) + 1;

    // ���ڿ� ���̸�ŭ ���� �Ҵ� �� ���ڿ� ����
    str = new char[length];
    strcpy_s(str, length, _str);
}
