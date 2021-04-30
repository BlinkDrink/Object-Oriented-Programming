//#define CATCH_CONFIG_MAIN 
#include"DynArray.h"
using std::cout;

void multiplyByTwo(int* a) {
	(*a) *= 2;
}

bool isEven(int a) {
	return a % 2 == 0;
}

int main() {
	DynArray arr;

	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(5);
	arr.push_back(4);
	arr.push_back(3);

	arr.filter(isEven); // arr.filter([](int a) {return a % 2 == 0; });
	arr.printItems();
}