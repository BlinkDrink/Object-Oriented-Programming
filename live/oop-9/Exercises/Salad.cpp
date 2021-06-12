#include "Salad.h"
#include<iostream>

using std::cout;

Salad::Salad(double weight, size_t parts, double price, size_t num_products, bool isSeasoned)
	: Food(weight, parts, price), num_products(num_products), isSeasoned(isSeasoned)
{
}

void Salad::print() const
{
	Food::print();
	cout << " " << num_products << " " << (isSeasoned ? "yes" : "no") << '\n';
}
