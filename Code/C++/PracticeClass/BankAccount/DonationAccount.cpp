#include "DonationAccount.h"
#include <iostream>

DonationAccount::DonationAccount(int _id, const char* _name)
	: Account(_id, _name, 0), donationMoney(0)
{
	SetAccountVal(2);
}

DonationAccount::DonationAccount(int _id, const char* _name, int _balance, int _donationMoney)
	: Account(_id, _name, _balance), donationMoney(_donationMoney)
{
	SetAccountVal(2);
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
