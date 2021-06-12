#pragma once
class Food {
private:
	double weight;
	size_t parts;
	double weight_per_part;
	double price;
public:
	Food(double weight, size_t parts, double price);

	void consume();
	void print() const;

	double getWeight();
	size_t getParts();
	double getWeightPerPart();
	double getPrice();
};