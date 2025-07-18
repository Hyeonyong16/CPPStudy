#pragma once

class Account;

class Bank
{
public:
	Bank();
	~Bank();

	void Run();					// 계좌 관리 프로그램 실행

	void CreateAccount();		// 계좌 개설
	void Deposit();				// 입금
	void Withdraw();			// 출금
	void Inquire();				// 전체 고객 잔액 조회

private:
	Account* accounts[100] = { };
};

