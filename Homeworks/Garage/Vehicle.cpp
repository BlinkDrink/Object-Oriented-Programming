#include "Vehicle.h"
#include<stdexcept>

Vehicle::Vehicle(const char* registration, const char* description, size_t space)
{
	if (space == 0)
	{
		throw std::invalid_argument("Car space cannot be less than 1.");
	}

	this->VIN = registration;
	this->descr = description;
	this->parkSpaces = space;
}

const char* Vehicle::registration() const
{
	return this->VIN.c_str();
}

const char* Vehicle::description() const
{
	return this->descr.c_str();
}

size_t Vehicle::space() const
{
	return this->parkSpaces;
}