#include "Account.h"

class Bank {
private:
	char* bankName;
	size_t capacity;
	Account** accounts;
	size_t size;
public:
	Bank(size_t capacity, const char* bankName);

	void transfer(const char* from, const char* to, double money);
	int getAccountIndexByName(const char* name);

	const char* getName();
	size_t getSize();
	Account& at(size_t pos);
	void addAccount(Account& a);

	~Bank();
};