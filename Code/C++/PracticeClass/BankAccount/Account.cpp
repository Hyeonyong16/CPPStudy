#include "Account.h"
#include <iostream>

Account::Account()
	: id(0), name(nullptr), balance(0)
{
}

Account::Account(int _id, const char* _name)
	: id(_id), balance(0)
{
	size_t length = strlen(_name) + 1;
	name = new char[length];
	strcpy_s(name, length, _name);
}

Account::~Account()
{
	if (nullptr != name)
	{
		delete[] name;
		name = nullptr;
	}
}

void Account::SetName(const char* _name)
{
}
