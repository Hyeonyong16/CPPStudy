#pragma once
class Account
{
public:
	Account();
	Account(int _id, const char* _name, int _accountVal = 0);	// �����ϸ� �ܾ��� 0���̴ϱ�

	Account(const Account& _origin);		// ���������

	virtual ~Account();

	inline int		GetId() const { return id; }
	inline char*	GetName() const { return name; }
	inline int		GetBalance() const { return balance; }
	inline int		GetAccountVal() const { return accountVal; }

	void SetId(const int _id) { id = _id; }
	//void SetName(const char* _name);
	void SetBalance(const int _balance) { balance = _balance; }
	void SetAccountVal(const int _val) { accountVal = _val; }

	virtual void Deposit(int money);
	virtual void Withdraw(int money);
	virtual void Print();

private:
	int			id = 0;				// ���¹�ȣ
	char*		name = nullptr;		// �� �̸�
	int			balance = 0;		// �ܾ�

	int			accountVal = 0;		// ���� ����
};

