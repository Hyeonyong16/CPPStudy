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

	Account* FindAccount(int _id);			// 계좌 번호로 계좌 순서 찾는 함수



private:
	Account*	accounts[100] = { };	// 계좌 정보가 들어있는 배열
	int			accountNum = 0;			// 현재 개설된 계좌 수
};

