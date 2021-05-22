#pragma once
#include "Registration.h"
using std::ostream;

class Vehicle {
private:
	Registration regnum;
	string description;
	unsigned int ownerID;
public:
	Vehicle(const string& regnum, const string& description);

	const string& getRegistration() const;
	size_t getOwnerID() const;
	void setOwnerId(unsigned int id);
	friend ostream& operator<<(ostream& o, const Vehicle& v);
};
