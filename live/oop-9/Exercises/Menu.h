#include "Food.h"
#include<vector>

using std::vector;

class Menu {
private:
	vector<Food*> list;
public:
	Menu();

	void addFood(Food& food);
	void removeFood(Food& food);
	int findFoodIndex(const Food& food) const;

	void printMenu() const;
	void printCheapestProduct() const;
};