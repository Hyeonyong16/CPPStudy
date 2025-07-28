#include "String.h"

String::String()
    :str(nullptr)
{
}

String::String(const char* _str)
{
    size_t length = strlen(_str) + 1;
    str = new char[length];
    strcpy_s(str, length, _str);
}

String::String(const String& _other)
{
    size_t length = strlen(_other.str) + 1;
    str = new char[length];
    strcpy_s(str, length, _other.str);
}

String::~String()
{
    if (nullptr != str)
    {
        delete[] str;
        str = nullptr;
    }
}

String& String::operator=(const char* _str)
{
    if (str != nullptr)
    {
        delete[] str;
    }

    size_t length = strlen(_str) + 1;
    str = new char[length];
    strcpy_s(str, length, _str);

    return *this;
}

String String::operator+(const char* _str)
{
    size_t length = strlen(str) + strlen(_str) + 1;
    char* temp = new char[length];


    strcat_s(str, length+ , _str);
    return *this;
}

String String::operator+(const String& _other)
{
}

String& String::operator+=(const char* _str)
{
}

String& String::operator+=(const String& _other)
{
}

bool String::operator==(const char* _str)
{
    return false;
}

bool String::operator==(const String& _other)
{
    return false;
}

std::ostream& operator<<(std::ostream& outStream, const String& other)
{
    // TODO: 여기에 return 문을 삽입합니다.
}

std::istream& operator>>(std::istream& inStream, String& other)
{
    // TODO: 여기에 return 문을 삽입합니다.
}
