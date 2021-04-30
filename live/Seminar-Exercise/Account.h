#include<iostream>
#include<cassert>

class Account {
private:
	char* name;
	double money;
public:
	Account(const char* name);

	const char* getName();
	double getMoney();

	void setMoney(double m);

	//std::ostream& operator<<(std::ostream& out, Account a);

	~Account();
};