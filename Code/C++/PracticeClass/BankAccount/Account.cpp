#include "Account.h"
#include <iostream>

Account::Account()
	: id(0), name(nullptr), balance(0), accountVal(0)
{
}

Account::Account(int _id, const char* _name, int _accountVal)
	: id(_id), balance(0), accountVal(_accountVal)
{
	size_t length = strlen(_name) + 1;
	name = new char[length];
	strcpy_s(name, length, _name);
}

Account::Account(const Account& _origin)
{
	id = _origin.id;
	balance = _origin.balance;
	accountVal = _origin.accountVal;

	int length = strlen(_origin.name) + 1;
	name = new char[length];
	strcpy_s(name, length, _origin.name);
}

Account::~Account()
{
	if (nullptr != name)
	{
		delete[] name;
		name = nullptr;
	}
}

void Account::Deposit(int _money)
{
	// 입력 금액이 0보다 적을 때
	if (_money < 0)
	{
		std::cout << "입력 금액이 0원보다 작습니다.\n";
	}
	else
	{
		balance += _money;
		std::cout << _money << "원 입금하였습니다. 현재 잔고: " << balance << "\n";
	}
}

void Account::Withdraw(int _money)
{
	// 입력 금액이 0보다 적을 때
	if (_money < 0)
	{
		std::cout << "입력 금액이 0원보다 작습니다.\n";
		return;
	}

	// 입력 금액보다 잔고가 적을 때
	if (_money > balance)
	{
		std::cout << "잔고가 입력 금액보다 적습니다.\n";
	}
	else
	{
		balance -= _money;
		std::cout << _money << "원 출금하였습니다. 현재 잔고: " << balance << "\n";
	}
}

void Account::Print()
{
	std::cout << "계좌번호: " << id
		<< "\n고객 이름: " << name
		<< "\n잔액: " << balance << "\n\n";
}
