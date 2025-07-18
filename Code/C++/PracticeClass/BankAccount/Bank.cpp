#include "Bank.h"

#include <iostream>
#include "Account.h"

Bank::Bank()
{
	for (int i = 0; i < 100; ++i)
	{
		accounts[i] = nullptr;
	}
}

Bank::~Bank()
{
	
}

void Bank::Run()
{
	int input = 0;

	while (true)
	{
		if (input == 'q' || input == 'Q') {
			std::cout << "종료합니다.\n";
			break;
		}

		std::cout
			<< "1.계좌개설, 2.입금, 3.출금, 4:전체 고객 잔액 조회, Q:종료\n"
			<< "키를 입력해주세요: ";

		std::cin >> input;
		switch (input)
		{
		case 1:
			CreateAccount();
			break;
		case 2:
			Deposit();
			break;
		case 3:
			Withdraw();
			break;
		case 4:
			Inquire();
			break;
		case 'Q':
		case 'q':
			break;
		default:
			std::cout << "잘못 입력하셨습니다.\n";
			break;
		}
	}
}

void Bank::CreateAccount()
{
}

void Bank::Deposit()
{
}

void Bank::Withdraw()
{
}

void Bank::Inquire()
{
}
