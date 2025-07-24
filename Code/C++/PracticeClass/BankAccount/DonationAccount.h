#pragma once
#include "Account.h"

class DonationAccount :
    public Account
{
public:
	DonationAccount();
	DonationAccount(int _id, const char* _name);
	~DonationAccount();

	int GetDonationMoney() const { return donationMoney; }


	virtual void Deposit(int _money) override;
	virtual void Print() override;
private:
    int donationMoney;
};

