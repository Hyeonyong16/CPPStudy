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
			std::cout << "�����մϴ�.\n";
			break;
		}

		std::cout
			<< "1.���°���, 2.�Ա�, 3.���, 4:��ü �� �ܾ� ��ȸ, Q:����\n"
			<< "Ű�� �Է����ּ���: ";

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
			std::cout << "�߸� �Է��ϼ̽��ϴ�.\n";
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
