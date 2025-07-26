#include "Bank.h"

#include <iostream>
#include <cassert>

#include "Account.h"
#include "CreditAccount.h"
#include "DonationAccount.h"

#define DIVIDELINE(NAME) std::cout << "====="#NAME"=====\n";

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

// 기본 메뉴 구동
void Bank::Run()
{
	Load();
	char input = 0;
	while (true)
	{
		DIVIDELINE(Menu)
			std::cout
			<< "1.계좌개설, 2.입금, 3.출금, 4:전체 고객 잔액 조회, Q:종료\n"
			<< "키를 입력해주세요: ";

		std::cin >> input;
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
			std::cout << "종료합니다.\n";
			Save();
			return;
		default:
			std::cout << "잘못 입력하셨습니다.\n";
			break;
		}
	}
}

// 계좌 개설
void Bank::CreateAccount()
{
	DIVIDELINE(CreatAccount)
		// 개설할 계좌의 정보를 받음
		int id;
	int Accountval;	// 1: 일반, 2: 신용, 3: 기부
	char name[100] = { };
	std::cout << "계좌번호를 입력: ";
	std::cin >> id;

	std::cout << "고객 이름을 입력: ";
	std::cin >> name;

	std::cout << "계좌 종류 입력(1 일반, 2 신용, 3 기부): ";
	std::cin >> Accountval;

	if (Accountval == 1)
	{
		// 마지막 계좌 뒤 순서에 새로운 계좌 생성
		accounts[accountNum] = new Account(id, name, 0);
	}
	else if (Accountval == 2)
	{
		// 마지막 계좌 뒤 순서에 새로운 계좌 생성
		accounts[accountNum] = new CreditAccount(id, name);
	}
	else if (Accountval == 3)
	{
		// 마지막 계좌 뒤 순서에 새로운 계좌 생성
		accounts[accountNum] = new DonationAccount(id, name);
	}
	else
	{
		std::cout << "계좌 종류를 잘못 입력하셨습니다.\n";
		return;
	}

	// 계좌가 생성되었으니 계좌 수 증가
	++accountNum;
}

// 입금 기능
void Bank::Deposit()
{
	DIVIDELINE(Deposit)
		int id;
	int money;
	std::cout << "계좌번호를 입력: ";
	std::cin >> id;

	std::cout << "입금 금액 입력: ";
	std::cin >> money;

	// 배열에서 계좌 찾기 
	Account* userAccount = FindAccount(id);

	// 계좌가 없을 경우 예외처리
	if (nullptr == userAccount)
	{
		std::cout << "\n계좌번호가 존재하지 않습니다.\n";
		return;
	}

	userAccount->Deposit(money);
}

// 출금 기능
void Bank::Withdraw()
{
	// todo: 테스트
	DIVIDELINE(Withdraw)
		int id;
	int money;
	std::cout << "계좌번호를 입력: ";
	std::cin >> id;

	// 배열에서 계좌 찾기 
	Account* userAccount = FindAccount(id);

	// 계좌가 없을 경우 예외처리
	if (nullptr == userAccount)
	{
		std::cout << "\n계좌번호가 존재하지 않습니다.\n";
		return;
	}

	std::cout << userAccount->GetBalance() << "원 있습니다.\n";
	std::cout << "출금할 금액을 입력: ";
	std::cin >> money;

	userAccount->Withdraw(money);
}

// 현재 저장된 계좌의 정보를 전부 출력하는 함수
void Bank::Inquire()
{
	DIVIDELINE(Inquire)
		// 현재 계좌 개수만큼 반복문
		for (int i = 0; i < accountNum; ++i)
		{
			accounts[i]->Print();
		}
}

// 입력받은 id로 동일한 id의 계좌를 찾는 함수
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

void Bank::Save()
{
	FILE* file = nullptr;
	fopen_s(&file, "AccountInfo.txt", "w");
	if (nullptr != file)
	{
		fprintf(file,
			"accountNum=%d\n",
			accountNum
		);
		for (int i = 0; i < accountNum; ++i)
		{
			fprintf(file,
				"accountval=%d id=%d name=%s balance=%d ",
				accounts[i]->GetAccountVal(), accounts[i]->GetId(), accounts[i]->GetName(), accounts[i]->GetBalance()
			);

			if (accounts[i]->GetAccountVal() == 2)
			{
				DonationAccount* tempAcc = dynamic_cast<DonationAccount*>(accounts[i]);
				assert(tempAcc);

				fprintf(file,
					"donationMoney=%d ",
					tempAcc->GetDonationMoney()
				);
			}
			fprintf(file,
				"\n");
		}
	}

	fclose(file);
}

void Bank::Load()
{
	int _accountVal = 0;
	int _id = 0;
	char _name[255] = { };
	int _balance = 0;
	int _donationMoney = 0;
	int _accountNum = 0;

	FILE* file = nullptr;
	fopen_s(&file, "AccountInfo.txt", "r");
	if (nullptr == file)
	{
		std::cout << "파일이 없습니다.\n";
		return;
	}

	fscanf_s(file,
		"accountNum=%d\n",
		&accountNum
	);

	for (int i = 0; i < accountNum; ++i)
	{
		fscanf_s(file,
			"accountval=%d id=%d name=%s balance=%d ",
			&_accountVal, &_id, _name, 255, &_balance
		);

		if (_accountVal == 2)
		{
			fscanf_s(file,
				"donationMoney=%d ",
				&_donationMoney
			);

			accounts[i] = new DonationAccount(_id, _name, _balance, _donationMoney);

		}
		else  if (_accountVal == 1)
		{
			accounts[i] = new CreditAccount(_id, _name, _balance);
		}
		else
		{
			accounts[i] = new Account(_id, _name, _balance);
		}

		fscanf_s(file,
			"\n"
		);
	}

	fclose(file);
}

