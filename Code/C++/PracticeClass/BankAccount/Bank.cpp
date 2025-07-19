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
	// 현재 계좌 개수만큼 반복문
	for (int i = 0; i < accountNum; ++i)
	{
		delete accounts[i];
		accounts[i] = nullptr;
	}
}

void Bank::Run()
{
	char input = 0;
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
		std::cin.get();
		switch (input)
		{
		case '1':
			CreateAccount();
			break;
		case '2':
			Deposit();
			break;
		case '3':
			Withdraw();
			break;
		case '4':
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
	char name[100] = { };
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

	Account* userAccount = FindAccount(id);
	if (nullptr == userAccount)
	{
		std::cout << "\n계좌번호가 존재하지 않습니다.\n\n\n";
		return;
	}

	else
	{
		userAccount->SetBalance(userAccount->GetBalance() + money);
		std::cout << "\n" << money << "원 입금하였습니다. 현재 잔액: " << userAccount->GetBalance() << "\n\n\n";
	}
}

void Bank::Withdraw()
{
	int id;
	int money;
	std::cout << "\n계좌번호를 입력: ";
	std::cin >> id;

	Account* userAccount = FindAccount(id);
	if (nullptr == userAccount)
	{
		std::cout << "\n계좌번호가 존재하지 않습니다.\n\n\n";
		return;
	}

	else
	{
		std::cout << "\n" << userAccount->GetBalance() << "원 있습니다.\n";
		std::cout << "출금할 금액을 입력: ";
		std::cin >> money;

		if (money > userAccount->GetBalance())
		{
			std::cout << "\n잔고보다 금액이 많습니다.\n\n\n";
		}
		else
		{
			userAccount->SetBalance(userAccount->GetBalance() - money);
			std::cout << "\n" << money << "원 출금하였습니다. 현재 잔액: " << userAccount->GetBalance() << "\n\n\n";
		}
	}
}

void Bank::Inquire()
{
	// 현재 계좌 개수만큼 반복문
	for (int i = 0; i < accountNum; ++i)
	{
		std::cout << "\n계좌번호: " << accounts[i]->GetId()
			<< " 고객 이름: " << accounts[i]->GetName()
			<< " 잔액: " << accounts[i]->GetBalance();
	}

	std::cout << "\n\n\n";
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

