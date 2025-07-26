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
	Load();
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
			Save();
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

	if (Accountval == 1)
	{
		// ������ ���� �� ������ ���ο� ���� ����
		accounts[accountNum] = new Account(id, name, 0);
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
		std::cout << "������ �����ϴ�.\n";
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

