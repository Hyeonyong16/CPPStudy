#pragma once

class NameCard
{
public:
	NameCard();
	NameCard(const char* _name, const char* phone, const char* email, const char* job);
	NameCard(const NameCard& _origin);
	~NameCard();

	void ShowData() const;

private:
	char* name;
	char* phone;
	char* email;
	char* job;
};

