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
	// �Է� �ݾ��� 0���� ���� ��
	if (_money < 0)
	{
		std::cout << "�Է� �ݾ��� 0������ �۽��ϴ�.\n";
	}
	else
	{
		balance += _money;
		std::cout << _money << "�� �Ա��Ͽ����ϴ�. ���� �ܰ�: " << balance << "\n";
	}
}

void Account::Withdraw(int _money)
{
	// �Է� �ݾ��� 0���� ���� ��
	if (_money < 0)
	{
		std::cout << "�Է� �ݾ��� 0������ �۽��ϴ�.\n";
		return;
	}

	// �Է� �ݾ׺��� �ܰ� ���� ��
	if (_money > balance)
	{
		std::cout << "�ܰ� �Է� �ݾ׺��� �����ϴ�.\n";
	}
	else
	{
		balance -= _money;
		std::cout << _money << "�� ����Ͽ����ϴ�. ���� �ܰ�: " << balance << "\n";
	}
}

void Account::Print()
{
	std::cout << "���¹�ȣ: " << id
		<< "\n�� �̸�: " << name
		<< "\n�ܾ�: " << balance << "\n\n";
}
