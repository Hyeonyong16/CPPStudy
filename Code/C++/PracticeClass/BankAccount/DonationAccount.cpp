#include "DonationAccount.h"
#include <iostream>

DonationAccount::DonationAccount(int _id, const char* _name)
	: Account(_id, _name, 2), donationMoney(0)
{
}

DonationAccount::~DonationAccount()
{
}

void DonationAccount::Deposit(int _money)
{
	Account::Deposit((int)((float)_money * 0.9f));

	donationMoney += (int)((float)_money * 0.1f);
}

void DonationAccount::Print()
{
	std::cout << "°èÁÂ¹øÈ£: " << GetId()
		<< "\n°í°´ ÀÌ¸§: " << GetName()
		<< "\nÀÜ¾×: " << GetBalance()
		<< "\n±âºÎ±Ý: " << donationMoney << "\n\n";

}
