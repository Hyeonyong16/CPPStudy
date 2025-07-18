#include "NameCard.h"

#include <iostream>

// ���ڿ� ���� �Ҵ� ��ũ��
#define SETSTRING(NAME) { size_t length = strlen(_##NAME) + 1;\
						NAME = new char[length];\
						strcpy_s(NAME, length, _##NAME); }

// ���� �Ҵ� ���� ��ũ��
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
		<< "�̸�: " << name << "\n"
		<< "��ȭ��ȣ: " << phone << "\n"
		<< "�̸���: " << email << "\n"
		<< "����: " << job << "\n";
}
