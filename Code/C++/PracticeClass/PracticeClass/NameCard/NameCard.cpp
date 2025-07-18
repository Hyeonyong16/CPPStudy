#include "NameCard.h"

#include <iostream>

// 문자열 동적 할당 매크로
#define SETSTRING(NAME) { size_t length = strlen(_##NAME) + 1;\
						NAME = new char[length];\
						strcpy_s(NAME, length, _##NAME); }

// 동적 할당 해제 매크로
#define DELETEARRAY(NAME) if (nullptr != NAME)\
					{\
						delete[] NAME;\
						NAME = nullptr;\
					}\

NameCard::NameCard()
	: name(nullptr), phone(nullptr), email(nullptr), job(nullptr)
{
}

NameCard::NameCard(const char* _name, const char* _phone, const char* _email, const char* _job)
{
	SETSTRING(name);
	SETSTRING(phone);
	SETSTRING(email);
	SETSTRING(job);
}

NameCard::~NameCard()
{
	DELETEARRAY(name);
	DELETEARRAY(phone);
	DELETEARRAY(email);
	DELETEARRAY(job);
}

void NameCard::ShowData() const
{
	std::cout
		<< "이름: " << name << "\n"
		<< "전화번호: " << phone << "\n"
		<< "이메일: " << email << "\n"
		<< "직업: " << job << "\n";
}
