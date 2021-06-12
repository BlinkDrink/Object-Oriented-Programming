#include "Food.h"
#include<iostream>

using std::cout;

Food::Food(double weight, size_t parts, double price)
	: weight(weight), parts(parts), weight_per_part(weight / parts), price(price) {}

void Food::consume() {
	parts--;
	weight -= weight_per_part;
}

void Food::print() const {
	cout << weight << " " << parts << " " << weight_per_part << " " << price;
}

double Food::getWeight() { return weight; }
size_t Food::getParts() { return parts; }
double Food::getWeightPerPart() { return weight_per_part; }
double Food::getPrice() { return price; }

