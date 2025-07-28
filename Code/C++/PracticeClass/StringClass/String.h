#pragma once
#include <iostream>

class String
{
public:
	String();
	String(const char* _str);
	String(const String& _other);
	~String();

	String& operator=(const char* _str);

	String operator+(const char* _str);
	String operator+(const String& _other);
	String& operator+=(const char* _str);
	String& operator+=(const String& _other);

	bool operator==(const char* _str);
	bool operator==(const String& _other);

	friend std::ostream& operator<<(std::ostream& outStream, const String& other);
	friend std::istream & operator>>(std::istream & inStream, String & other);

private:
	char* str = nullptr;
};

