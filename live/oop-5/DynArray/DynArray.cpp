#include "DynArray.h"
#include<cassert>

using std::cout;
using std::swap;

DynArray::DynArray() {
	this->size = 0;
	this->capacity = 1;
	this->arr = new int[capacity];
	assert(this->arr);
}

DynArray::~DynArray() {
	delete[] this->arr;
}

void DynArray::resize() {
	int* newArr = new int[this->capacity * 2];
	assert(newArr);

	for (unsigned i = 0; i < this->size; i++)
	{
		newArr[i] = this->arr[i];
	}

	delete[] this->arr;
	this->arr = newArr;
	this->capacity *= 2;
}

void DynArray::push_back(int item) {
	if (this->size == this->capacity)
	{
		resize();
	}

	this->arr[this->size] = item;
	this->size++;
}

int DynArray::pop_back() {
	int item = this->arr[this->size];
	this->size--;
	return item;
}

int DynArray::get(unsigned index) {
	assert(index < size);
	return this->arr[index];
}

void DynArray::shiftElementsLeft(unsigned index) {
	for (unsigned i = index; i < this->size - 1; i++)
	{
		swap(this->arr[i], this->arr[i + 1]);
	}
}

int DynArray::remove(unsigned index) {
	assert(index < this->size);

	int item = this->arr[this->size - 1];
	shiftElementsLeft(index);
	this->size--;

	return item;
}

void DynArray::map(void (*f)(int*)) {
	for (unsigned i = 0; i < this->size; i++)
	{
		f(&this->arr[i]);
	}
}

void DynArray::filter(bool (*f)(int)) {
	for (unsigned i = 0; i < this->size; i++)
	{
		if (!f(this->arr[i]))
		{
			remove(i);
		}
	}
}

void DynArray::printItems() {
	for (unsigned i = 0; i < this->size; i++)
	{
		cout << this->arr[i] << ' ';
	}
}


