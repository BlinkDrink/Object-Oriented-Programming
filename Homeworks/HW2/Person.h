#pragma once
#include "Vehicle.h"
#include <string>
#include <vector>

using std::vector;
using std::string;

class Person {
private:
	string name;
	size_t ID;
	vector<Registration> vehicles;
public:
	Person(const string& name, unsigned int id);

	size_t getID() const;

	void addVehicleRegNum(const string& reg);
	void removeVehicleRegNum(const string& reg);
	int findVehicle(const string& reg) const;
	const string& getRegistrationAtIndex(size_t index) const;

	size_t getVehicleCount() const;
	friend ostream& operator<<(ostream& o, const Person& p);
};