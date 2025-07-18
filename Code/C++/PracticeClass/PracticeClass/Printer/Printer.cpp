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
    // 문자열이 설정되지 않았을 경우 예외처리
    if (nullptr == str) { std::cout << "Can’t show the string value\n"; return; }

    // 문자열이 설정되어 있으면 출력
    std::cout << str << std::endl;

    // 문자열 출력 후 문자열 설정 해제(메모리 할당도 해제)
    delete[] str;
    str = nullptr;
}

void Printer::SetString(const char* _str)
{
    // 입력받은 문자열 길이
    size_t length = strlen(_str) + 1;

    // 문자열 길이만큼 동적 할당 및 문자열 복사
    str = new char[length];
    strcpy_s(str, length, _str);
}
