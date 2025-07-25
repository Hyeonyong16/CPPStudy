#pragma once
class Account
{
public:
	Account();
	Account(int _id, const char* _name, int _accountVal = 0);	// 개설하면 잔액은 0원이니까

	Account(const Account& _origin);		// 복사생성자

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
	int			id = 0;				// 계좌번호
	char*		name = nullptr;		// 고객 이름
	int			balance = 0;		// 잔액

	int			accountVal = 0;		// 계좌 종류
};

