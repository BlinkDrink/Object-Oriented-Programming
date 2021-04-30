#include "Bank.h"
#include "helpers.h"

Bank::Bank(size_t capacity, const char* bankName) {
	unsigned bankNameLen = getStrLen(bankName);
	this->bankName = new char[bankNameLen + 1];

	for (size_t i = 0; i < bankNameLen; i++)
	{
		this->bankName[i] = bankName[i];
	}

	this->bankName[bankNameLen] = '\0';

	this->capacity = capacity;
	this->accounts = new Account * [capacity];
	this->size = 0;
}

int Bank::getAccountIndexByName(const char* name) {
	for (size_t i = 0; i < this->size; i++)
	{
		if (stringCompare(this->accounts[i]->getName(), name) == 0) {
			return i;
		}
	}

	return -1;
}

void Bank::transfer(const char* from, const char* to, double money) {
	unsigned fromIndex = this->getAccountIndexByName(from);
	unsigned toIndex = this->getAccountIndexByName(to) != -1;
	assert(fromIndex != -1 && toIndex != -1);

	Account* a = this->accounts[fromIndex];
	Account* b = this->accounts[toIndex];
	assert(a->getMoney() - money >= 0);

	a->setMoney(a->getMoney() - money);
	b->setMoney(b->getMoney() + money);
}

const char* Bank::getName() {
	return this->bankName;
}

size_t Bank::getSize() {
	return this->size;
}

Account& Bank::at(size_t pos) {
	assert(pos <= this->size);

	return *this->accounts[pos];
}

void Bank::addAccount(Account& a) {
	assert(this->size + 1 < capacity);
	assert(getAccountIndexByName(a.getName()) == -1);

	this->accounts[this->size] = &a;

	this->size++;
}

Bank::~Bank() {
	delete[] this->bankName;
	delete[] this->accounts;
	this->size = 0;
	this->capacity = 0;
}