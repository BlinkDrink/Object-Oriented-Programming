#include<iostream>

class DynArray {
private:
	unsigned capacity;
	unsigned size;
	int* arr;

	void resize();
	void shiftElementsLeft(unsigned index);
public:
	DynArray();
	~DynArray();

	void push_back(int item);
	int pop_back();
	int get(unsigned index);
	int remove(unsigned index);
	void map(void (*f)(int*));
	void filter(bool (*f)(int));
	void printItems();
};