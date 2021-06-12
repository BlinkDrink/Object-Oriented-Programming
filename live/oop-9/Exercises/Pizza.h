#pragma once
#include "Food.h"
#include<string>

using std::string;

class Pizza : public Food {
private:
	string pizza_type;
public:
	Pizza(double weight, size_t parts, double price, const string& piza_type);

	void print() const;
};