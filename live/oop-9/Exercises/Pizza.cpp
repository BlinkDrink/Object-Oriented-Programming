#include "Pizza.h"
#include<iostream>

using std::cout;

Pizza::Pizza(double weight, size_t parts, double price, const string& pizza_type)
	: Food(weight, parts, price), pizza_type(pizza_type)
{
}

void Pizza::print() const {
	Food::print();
	cout << " " << pizza_type << '\n';
}