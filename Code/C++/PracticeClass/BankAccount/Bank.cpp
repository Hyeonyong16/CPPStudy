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
	// ������ ������ ������ ����
	int id;
	char* name;
	std::cout << "\n���¹�ȣ�� �Է�: ";
	std::cin >> id;

	std::cout << "\n�� �̸��� �Է�: ";
	std::cin >> name;

	// ������ ���� �� ������ ���ο� ���� ����
	accounts[accountNum] = new Account(id, name);

	// ���°� �����Ǿ����� ���� �� ����
	++accountNum;

	std::cout << "\n\n\n";
}

void Bank::Deposit()
{
	int id;
	int money;
	std::cout << "\n���¹�ȣ�� �Է�: ";
	std::cin >> id;

	std::cout << "\n�Ա� �ݾ� �Է�: ";
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
	// ���� ���� ������ŭ �ݺ���
	for (int i = 0; i < accountNum; ++i)
	{
		// ������ ���¹�ȣ�� ������ �ش� ���� ������ ��ȯ
		if (accounts[i]->GetId() == _id)
			return accounts[i];
	}

	// ���°� ������ nullptr ��ȯ
	return nullptr;
}

