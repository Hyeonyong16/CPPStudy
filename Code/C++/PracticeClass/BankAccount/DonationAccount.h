#pragma once
#include "Account.h"

class DonationAccount :
    public Account
{
public:
	DonationAccount(int _id, const char* _name);
	DonationAccount(int _id, const char* _name, int _balance, int _donationMoney);
	~DonationAccount();

	int GetDonationMoney() const { return donationMoney; }


	virtual void Deposit(int _money) override;
	virtual void Print() override;
private:
    int donationMoney;
};

