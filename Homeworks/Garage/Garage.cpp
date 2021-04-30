#include "Garage.h"
#include<iostream>
#include<cstring>

#define NDEBUG
#include<cassert>

using std::swap;

Garage::Garage(const Garage& g)
{
	this->capacity = g.capacity;
	this->currentTakenSpaces = g.currentTakenSpaces;
	this->numVehicles = g.numVehicles;
	this->vehicles = new Vehicle * [g.numVehicles];
	for (size_t i = 0; i < g.numVehicles; i++)
	{
		this->vehicles[i] = g.vehicles[i];
	}
}

Garage& Garage::operator=(const Garage& g)
{
	if (this == &g)
	{
		return *this;
	}

	delete[] this->vehicles;
	this->capacity = g.capacity;
	this->currentTakenSpaces = g.currentTakenSpaces;
	this->numVehicles = g.numVehicles;
	this->vehicles = new Vehicle * [g.numVehicles];
	for (size_t i = 0; i < g.numVehicles; i++)
	{
		this->vehicles[i] = g.vehicles[i];
	}

	return *this;
}

Garage::Garage(Garage&& g) noexcept
{
	this->capacity = g.capacity;
	g.capacity = 0;

	this->currentTakenSpaces = g.currentTakenSpaces;
	g.currentTakenSpaces = 0;

	this->numVehicles = g.numVehicles;
	g.numVehicles = 0;

	this->vehicles = g.vehicles;
	g.vehicles = nullptr;
}

Garage& Garage::operator=(Garage&& g) noexcept
{
	if (this == &g)
	{
		return *this;
	}

	this->capacity = g.capacity;
	g.capacity = 0;

	this->currentTakenSpaces = g.currentTakenSpaces;
	g.currentTakenSpaces = 0;

	this->numVehicles = g.numVehicles;
	g.numVehicles = 0;

	delete[] this->vehicles;
	this->vehicles = g.vehicles;
	g.vehicles = nullptr;

	return *this;
}

Garage::Garage(size_t size)
{
	if (size == 0)
	{
		throw std::invalid_argument("Cannot initialize garage with size 0.");
	}

	this->capacity = size;
	this->numVehicles = 0;
	this->currentTakenSpaces = 0;
	this->vehicles = new Vehicle * [size];
}

Garage::~Garage()
{
	delete[] this->vehicles;
	this->vehicles = nullptr;
}

void Garage::insert(Vehicle& v)
{
	if (this->currentTakenSpaces + v.space() > this->capacity)
	{
		throw std::out_of_range("Not enough space in the garage!");
	}

	if (find(v.registration()) != nullptr)
	{
		throw std::invalid_argument("There is a car with the same registration in the garage!");
	}

	this->vehicles[this->numVehicles] = &v;
	this->numVehicles++;
	this->currentTakenSpaces += v.space();
}

void Garage::erase(const char* registration)
{
	if (registration == nullptr)
	{
		throw std::invalid_argument("Cannot accept nullptr argument.");
	}

	for (size_t i = 0; i < this->numVehicles; i++)
	{
		if (this->vehicles[i] != nullptr)
		{
			if (strcmp(this->vehicles[i]->registration(), registration) == 0)
			{
				this->currentTakenSpaces -= this->vehicles[i]->space();
				this->vehicles[i] = nullptr;
				swap(this->vehicles[i], this->vehicles[this->numVehicles - 1]);
				this->numVehicles--;
			}
		}
	}
}

const Vehicle& Garage::at(size_t pos) const
{
	if (pos >= this->numVehicles)
	{
		throw std::out_of_range("Pos out of range.");
	}

	return *(this->vehicles[pos]);
}

const Vehicle& Garage::operator[](size_t pos) const
{
	assert(pos < this->numVehicles);
	return *this->vehicles[pos];
}

bool Garage::empty() const
{
	return this->numVehicles == 0;
}

size_t Garage::size() const
{
	return this->numVehicles;
}

void Garage::clear()
{
	for (size_t i = 0; i < this->numVehicles; i++)
	{
		this->vehicles[i] = nullptr;
	}

	this->numVehicles = 0;
	this->currentTakenSpaces = 0;
}

const Vehicle* Garage::find(const char* registration) const
{
	for (size_t i = 0; i < this->numVehicles; i++)
	{
		if (strcmp(this->vehicles[i]->registration(), registration) == 0)
		{
			return this->vehicles[i];
		}
	}

	return nullptr;
}