#pragma once
#include "MyString.h"
class Vehicle
{
private:
	MyString VIN;
	MyString descr;
	size_t parkSpaces;

public:
	Vehicle(const char* registration, const char* description, size_t space);
	const char* registration() const;
	const char* description() const;
	size_t space() const;
};
