#pragma once

class Account;

class Bank
{
public:
	Bank();
	~Bank();

	void Run();					// ���� ���� ���α׷� ����

	void CreateAccount();		// ���� ����
	void Deposit();				// �Ա�
	void Withdraw();			// ���
	void Inquire();				// ��ü �� �ܾ� ��ȸ

private:
	Account* accounts[100] = { };
};

