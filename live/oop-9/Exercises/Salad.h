#include "Food.h"

class Salad : public Food {
private:
	size_t num_products;
	bool isSeasoned;
public:
	Salad(double weight, size_t parts, double price, size_t num_products, bool isSeasoned);

	void print() const;
};