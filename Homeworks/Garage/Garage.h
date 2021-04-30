#pragma once
#include "Vehicle.h"
class Garage
{
private:
	size_t capacity = 0;
	size_t currentTakenSpaces = 0;
	size_t numVehicles = 0;
	Vehicle** vehicles = nullptr;
public:
	/**
	*  Copy constructor
	*
	*  @param g - garage to be copied
	*/
	Garage(const Garage& g);

	/**
	*  Copy assignment operator
	*
	*  @param g - garage to be copied
	*/
	Garage& operator=(const Garage& g);

	/**
	*  Move constructor
	*
	*  @param g - garage to be moved
	*/
	Garage(Garage&& g) noexcept;

	/**
	*  Move assignment operator
	*
	*  @param g - garage to be moved
	*/
	Garage& operator=(Garage&& g) noexcept;

	/**
	*  Garage constructor with 1 argument
	*
	*  @param size - size with which the garage will be initialzied
	*/
	Garage(size_t size);

	/**
	*  Destructor
	*/
	~Garage();

	/**
	*  Class method, inserts v in vehicles if there is enough space for it and
	*  there isn't a car with the same registration number.
	*
	*  @param v - vehicle to be inserted
	*/
	void insert(Vehicle& v);

	/**
	*  Class method, erases a vehicle with the given registration.
	*  If there is no car with such registration - do nothing;
	*
	*  @param registration - registration of the car to be removed
	*/
	void erase(const char* registration);

	/**
	*  Class method, same as the above but for constants.
	*  Throws if the index is out of range.
	*
	*  @param pos - index to be accessed
	**/
	const Vehicle& at(size_t pos) const;

	/**
	*  operator[], same as the above but for constants.
	*
	*  @param pos - index to be accessed
	*/
	const Vehicle& operator[](size_t pos) const;

	/**
	*  Class method, returns true if the garage is empty, false otherwise.
	*/
	bool empty() const;

	/**
	*  Class method, returns the number of cars in the garage.
	*/
	size_t size() const;

	/**
	*  Class method, clears the garage by removing all of the cars.
	*/
	void clear();

	/**
	*  Class method, same as the above but for Constants.
	*
	*  @param registration - registration of the car to be found
	*/
	const Vehicle* find(const char* registration) const;
};
