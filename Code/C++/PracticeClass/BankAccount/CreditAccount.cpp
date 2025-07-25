#include "CreditAccount.h"

CreditAccount::CreditAccount(int _id, const char* _name)
	: Account(_id, _name, 1)
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
