#pragma once
#include "Account.h"

// �ſ� ���� - �Ա� ������ 1% ���ڸ� ��
class CreditAccount :
	public Account
{
public:
	CreditAccount(int _id, const char* _name);
	CreditAccount(int _id, const char* _name, int _balance);
	~CreditAccount();

	virtual void Deposit(int _money) override;

private:

};

