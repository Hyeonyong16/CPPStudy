#pragma once
class Account
{
public:
	Account();
	Account(int _id, const char* _name, int _balance);
	~Account();

	int GetId() { return id; }
	char* GetName() { return name; }
	int GetBalance() { return balance; }

	void SetId(const int _id) { id = _id; }
	void SetName(const char* _name);
	void SetBalance(const int _balance) { balance = _balance; }

private:
	int			id = 0;				// °èÁÂ¹øÈ£
	char*		name = nullptr;		// °í°´ ÀÌ¸§
	int			balance = 0;		// ÀÜ¾×
};

