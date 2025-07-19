#pragma once
class Account
{
public:
	Account();
	Account(int _id, const char* _name);	// 개설하면 잔액은 0원이니까
	~Account();

	int GetId() { return id; }
	char* GetName() { return name; }
	int GetBalance() { return balance; }

	void SetId(const int _id) { id = _id; }
	//void SetName(const char* _name);
	void SetBalance(const int _balance) { balance = _balance; }

private:
	int			id = 0;				// 계좌번호
	char*		name = nullptr;		// 고객 이름
	int			balance = 0;		// 잔액
};

