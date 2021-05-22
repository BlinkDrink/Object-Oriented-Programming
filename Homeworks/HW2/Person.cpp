#include "Person.h"
#include <iostream>

using std::exception;
using std::invalid_argument;

Person::Person(const string& name, unsigned int id) : name(name), ID(id) {
}

unsigned int Person::getID() const {
	return this->ID;
}

void Person::removeVehicleRegNum(const string& reg) {
	int index = findVehicle(reg);
	if (index == -1)
	{
		throw exception("There is no vehicle with this registration owned by that person.");
	}

	vehicles.erase(vehicles.begin() + index);
}

void Person::addVehicleRegNum(const string& reg) {
	if (findVehicle(reg) != -1)
	{
		throw invalid_argument("There is already a vehicle with the same registration owned by that person.");
	}

	Registration r(reg);
	vehicles.push_back(r);
}

int Person::findVehicle(const string& reg) const {
	for (size_t i = 0; i < vehicles.size(); i++)
	{
		if (vehicles[i].toString() == reg)
		{
			return i;
		}
	}

	return -1;
}

size_t Person::getVehicleCount() const {
	return vehicles.size();
}

const string& Person::getRegistrationAtIndex(size_t index) const {
	return vehicles[index].toString();
}

ostream& operator<<(ostream& o, const Person& p) {
	o << "Person:\n" <<
		"\tName: " << p.name <<
		"\n\tID: " << p.ID <<
		"\n\tVehicles:\n";

	for (size_t i = 0; i < p.vehicles.size(); i++)
	{
		o << "\t\t" << p.vehicles[i].toString() << '\n';
	}

	return o;
}

