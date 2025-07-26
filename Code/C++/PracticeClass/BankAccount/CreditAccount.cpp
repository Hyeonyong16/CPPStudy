#include "CreditAccount.h"

CreditAccount::CreditAccount(int _id, const char* _name)
	: Account(_id, _name, 0)
{
	SetAccountVal(1);
}

CreditAccount::CreditAccount(int _id, const char* _name, int _balance)
	: Account(_id, _name, _balance)
{
	SetAccountVal(1);
}

CreditAccount::~CreditAccount()
{
}

void CreditAccount::Deposit(int _money)
{
	int myBalance = GetBalance();

	SetBalance(myBalance + (int)((float)_money * 1.1f));
}
