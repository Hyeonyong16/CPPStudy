#include "CreditAccount.h"

CreditAccount::CreditAccount()
	: Account()
{
}

CreditAccount::CreditAccount(int _id, const char* _name)
	: Account(_id, _name)
{
}

CreditAccount::~CreditAccount()
{
}

void CreditAccount::Deposit(int _money)
{
	int myBalance = GetBalance();

	SetBalance(myBalance + (int)((float)_money * 1.1f));
}
