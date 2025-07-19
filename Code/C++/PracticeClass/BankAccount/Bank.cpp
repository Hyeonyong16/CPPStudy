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
	// ���� ���� ������ŭ �ݺ���
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
			std::cout << "�����մϴ�.\n";
			break;
		}

		std::cout
			<< "1.���°���, 2.�Ա�, 3.���, 4:��ü �� �ܾ� ��ȸ, Q:����\n"
			<< "Ű�� �Է����ּ���: ";

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
			std::cout << "�߸� �Է��ϼ̽��ϴ�.\n";
			break;
		}
	}
}

void Bank::CreateAccount()
{
	// ������ ������ ������ ����
	int id;
	char name[100] = { };
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

	Account* userAccount = FindAccount(id);
	if (nullptr == userAccount)
	{
		std::cout << "\n���¹�ȣ�� �������� �ʽ��ϴ�.\n\n\n";
		return;
	}

	else
	{
		userAccount->SetBalance(userAccount->GetBalance() + money);
		std::cout << "\n" << money << "�� �Ա��Ͽ����ϴ�. ���� �ܾ�: " << userAccount->GetBalance() << "\n\n\n";
	}
}

void Bank::Withdraw()
{
	int id;
	int money;
	std::cout << "\n���¹�ȣ�� �Է�: ";
	std::cin >> id;

	Account* userAccount = FindAccount(id);
	if (nullptr == userAccount)
	{
		std::cout << "\n���¹�ȣ�� �������� �ʽ��ϴ�.\n\n\n";
		return;
	}

	else
	{
		std::cout << "\n" << userAccount->GetBalance() << "�� �ֽ��ϴ�.\n";
		std::cout << "����� �ݾ��� �Է�: ";
		std::cin >> money;

		if (money > userAccount->GetBalance())
		{
			std::cout << "\n�ܰ��� �ݾ��� �����ϴ�.\n\n\n";
		}
		else
		{
			userAccount->SetBalance(userAccount->GetBalance() - money);
			std::cout << "\n" << money << "�� ����Ͽ����ϴ�. ���� �ܾ�: " << userAccount->GetBalance() << "\n\n\n";
		}
	}
}

void Bank::Inquire()
{
	// ���� ���� ������ŭ �ݺ���
	for (int i = 0; i < accountNum; ++i)
	{
		std::cout << "\n���¹�ȣ: " << accounts[i]->GetId()
			<< " �� �̸�: " << accounts[i]->GetName()
			<< " �ܾ�: " << accounts[i]->GetBalance();
	}

	std::cout << "\n\n\n";
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

