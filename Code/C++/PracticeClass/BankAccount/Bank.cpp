#include "Bank.h"

#include <iostream>
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
	// ���� ���� ������ŭ �ݺ���
	for (int i = 0; i < accountNum; ++i)
	{
		delete accounts[i];
		accounts[i] = nullptr;
	}
}

// �⺻ �޴� ����
void Bank::Run()
{
	char input = 0;
	while (true)
	{		
		DIVIDELINE(Menu)
		std::cout
			<< "1.���°���, 2.�Ա�, 3.���, 4:��ü �� �ܾ� ��ȸ, Q:����\n"
			<< "Ű�� �Է����ּ���: ";

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
			std::cout << "�����մϴ�.\n";
			return;
		default:
			std::cout << "�߸� �Է��ϼ̽��ϴ�.\n";
			break;
		}
	}
}

// ���� ����
void Bank::CreateAccount()
{
	DIVIDELINE(CreatAccount)
	// ������ ������ ������ ����
	int id;
	int Accountval;	// 1: �Ϲ�, 2: �ſ�, 3: ���
	char name[100] = { };
	std::cout << "���¹�ȣ�� �Է�: ";
	std::cin >> id;

	std::cout << "�� �̸��� �Է�: ";
	std::cin >> name;

	std::cout << "���� ���� �Է�(1 �Ϲ�, 2 �ſ�, 3 ���): ";
	std::cin >> Accountval;

	if(Accountval == 1)
	{
		// ������ ���� �� ������ ���ο� ���� ����
		accounts[accountNum] = new Account(id, name);
	}
	else if (Accountval == 2)
	{
		// ������ ���� �� ������ ���ο� ���� ����
		accounts[accountNum] = new CreditAccount(id, name);
	}
	else if (Accountval == 3)
	{
		// ������ ���� �� ������ ���ο� ���� ����
		accounts[accountNum] = new DonationAccount(id, name);
	}
	else
	{
		std::cout << "���� ������ �߸� �Է��ϼ̽��ϴ�.\n";
		return;
	}

	// ���°� �����Ǿ����� ���� �� ����
	++accountNum;
}

// �Ա� ���
void Bank::Deposit()
{
	DIVIDELINE(Deposit)
	int id;
	int money;
	std::cout << "���¹�ȣ�� �Է�: ";
	std::cin >> id;

	std::cout << "�Ա� �ݾ� �Է�: ";
	std::cin >> money;

	// �迭���� ���� ã�� 
	Account* userAccount = FindAccount(id);

	// ���°� ���� ��� ����ó��
	if (nullptr == userAccount)
	{
		std::cout << "\n���¹�ȣ�� �������� �ʽ��ϴ�.\n";
		return;
	}

	userAccount->Deposit(money);
}

// ��� ���
void Bank::Withdraw()
{
	// todo: �׽�Ʈ
	DIVIDELINE(Withdraw)
	int id;
	int money;
	std::cout << "���¹�ȣ�� �Է�: ";
	std::cin >> id;

	// �迭���� ���� ã�� 
	Account* userAccount = FindAccount(id);

	// ���°� ���� ��� ����ó��
	if (nullptr == userAccount)
	{
		std::cout << "\n���¹�ȣ�� �������� �ʽ��ϴ�.\n";
		return;
	}

	std::cout << userAccount->GetBalance() << "�� �ֽ��ϴ�.\n";
	std::cout << "����� �ݾ��� �Է�: ";
	std::cin >> money;

	userAccount->Withdraw(money);
}

// ���� ����� ������ ������ ���� ����ϴ� �Լ�
void Bank::Inquire()
{
	DIVIDELINE(Inquire)
	// ���� ���� ������ŭ �ݺ���
	for (int i = 0; i < accountNum; ++i)
	{
		accounts[i]->Print();
	}
}

// �Է¹��� id�� ������ id�� ���¸� ã�� �Լ�
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

