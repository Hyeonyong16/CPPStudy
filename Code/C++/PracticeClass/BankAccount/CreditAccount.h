#pragma once
#include "Account.h"

// 신용 계좌 - 입금 때마다 1% 이자를 줌
class CreditAccount :
    public Account
{
public:
    CreditAccount(int _id, const char* _name);
    ~CreditAccount();

    virtual void Deposit(int _money) override;

private:

};

