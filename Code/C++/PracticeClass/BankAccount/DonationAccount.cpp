#include "DonationAccount.h"
#include <iostream>

DonationAccount::DonationAccount()
	: Account(), donationMoney(0)
{
}

DonationAccount::DonationAccount(int _id, const char* _name)
	: Account(_id, _name), donationMoney(0)
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
	std::cout << "���¹�ȣ: " << GetId()
		<< "\n�� �̸�: " << GetName()
		<< "\n�ܾ�: " << GetBalance()
		<< "\n��α�: " << donationMoney << "\n\n";

}
