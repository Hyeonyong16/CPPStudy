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

	Account* FindAccount(int _id);			// ���� ��ȣ�� ���� ���� ã�� �Լ�



private:
	Account*	accounts[100] = { };	// ���� ������ ����ִ� �迭
	int			accountNum = 0;			// ���� ������ ���� ��
};

