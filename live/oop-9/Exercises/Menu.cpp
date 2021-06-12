#include "Menu.h"

Menu::Menu()
{
}

void Menu::addFood(Food& food) {
	list.push_back(&food);
}

void Menu::removeFood(Food& food) {
	list.erase(list.begin() + findFoodIndex(food));
}

int Menu::findFoodIndex(const Food& food) const {
	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i] == &food)
		{
			return i;
		}
	}

	return -1;
}

void Menu::printMenu() const {
	for (auto var : list)
	{
		var->print();
	}
}

void Menu::printCheapestProduct() const {
	if (!list.size())
	{
		return;
	}

	Food* f = list[0];
	for (size_t i = 1; i < list.size(); i++)
	{
		if (f->getPrice() > list[i]->getPrice())
		{
			f = list[i];
		}
	}

	f->print();
}
