#pragma once
#include "Person.h"

class Database {
private:
	vector<Person> people;
	vector<Vehicle> vehicles;

	Database();
public:
	static Database& getInstance();
	Database(const Database&) = delete;
	Database& operator=(const Database&) = delete;
	Database(Database&&) = delete;
	Database& operator=(Database&&) = delete;

	void addPersonRecord(const string& name, unsigned int id);
	void deletePersonRecord(unsigned int id);
	Person* findPersonById(unsigned int id);

	void deleteVehicleRecord(const string& reg);
	void addVehicleRecord(const string& reg, const string& description);
	Vehicle* findVehicleByRegistration(const string& reg);

	void assignVehicleToOwner(unsigned ownerID, const string& vehicleID);
	void releaseVehicleOfOwner(unsigned ownerID, const string& vehicleID);

	bool isStringPersonID(const string& id) const;

	void menu() const;
	void printVehicles() const;
	void printPeople() const;

	void readFromFile(const string& path, vector<string>& cmdHistory);
	void saveToFile(const string& path, const vector<string>& cmdHistory) const;

	void exe();
};
