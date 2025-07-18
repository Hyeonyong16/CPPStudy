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
	// 개설할 계좌의 정보를 받음
	int id;
	char* name;
	std::cout << "\n계좌번호를 입력: ";
	std::cin >> id;

	std::cout << "\n고객 이름을 입력: ";
	std::cin >> name;

	// 마지막 계좌 뒤 순서에 새로운 계좌 생성
	accounts[accountNum] = new Account(id, name);

	// 계좌가 생성되었으니 계좌 수 증가
	++accountNum;

	std::cout << "\n\n\n";
}

void Bank::Deposit()
{
	int id;
	int money;
	std::cout << "\n계좌번호를 입력: ";
	std::cin >> id;

	std::cout << "\n입금 금액 입력: ";
	std::cin >> money;


}

void Bank::Withdraw()
{
}

void Bank::Inquire()
{
}

// 
Account* Bank::FindAccount(int _id)
{
	// 현재 계좌 개수만큼 반복문
	for (int i = 0; i < accountNum; ++i)
	{
		// 동일한 계좌번호가 있으면 해당 계좌 포인터 반환
		if (accounts[i]->GetId() == _id)
			return accounts[i];
	}

	// 계좌가 없으면 nullptr 반환
	return nullptr;
}

