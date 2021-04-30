#include "Account.h"
#include "helpers.h"

using std::cout;
using std::ostream;

Account::Account(const char* name) {
	unsigned nameLen = getStrLen(name);
	this->name = new char[nameLen + 1];

	for (size_t i = 0; i < nameLen; i++)
	{
		this->name[i] = name[i];
	}

	this->name[nameLen] = '\0';

	this->money = 0;
}

const char* Account::getName() {
	return this->name;
}

double Account::getMoney() {
	return this->money;
}

void Account::setMoney(double m) {
	assert(m >= 0);

	this->money = m;
}

//ostream& Account::operator<<(ostream& out, Account a) {
//	cout << a.getName() << ":" << a.getMoney();
//	return out;
//}

Account::~Account() {
	delete[] this->name;
	this->money = 0;
}