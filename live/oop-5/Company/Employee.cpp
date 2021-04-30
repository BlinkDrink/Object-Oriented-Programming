#include "Employee.h"

using std::cout;
using std::endl;

Employee::Employee() {
	this->name = nullptr;
	this->department = nullptr;
	this->age = 0;
	this->salary = 0;
}

void Employee::setName(const char name[]) {
	unsigned nameLen = strlen(name);
	this->name = new char[nameLen + 1];
	if (!this->name)
	{
		cout << "Not enough memory for name!";
		return;
	}
	strcpy_s(this->name, sizeof(char) * (nameLen + 1), name);
}

bool Employee::areEqual(Employee* e2) {
	if (strcmp(this->getName(), e2->getName()) != 0)
	{
		return false;
	}

	if (strcmp(this->getDepartment(), e2->getDepartment()) != 0)
	{
		return false;
	}

	if (this->getAge() != e2->getAge())
	{
		return false;
	}

	if (this->getSalary() != e2->getSalary())
	{
		return false;
	}

	return true;
}

void Employee::setDepartment(const char department[]) {
	unsigned depLen = strlen(department);
	this->department = new char[depLen + 1];
	if (!this->department)
	{
		cout << "Not enough memory for name!";
		return;
	}
	strcpy_s(this->department, sizeof(char) * (depLen + 1), department);
}

void Employee::setAge(unsigned age) {
	if (age < 18 || age > 64)
	{
		cout << "Invalid age!";
		return;
	}

	this->age = age;
}

void Employee::setSalary(double salary) {
	if (salary < 610 || salary > 1000)
	{
		cout << "Invalid salary!";
		return;
	}

	this->salary = salary;
}

const char* Employee::getName() const {
	return this->name;
}

const char* Employee::getDepartment() const {
	return this->department;
}

const unsigned Employee::getAge() const {
	return this->age;
}

const double Employee::getSalary() const {
	return this->salary;
}

Employee::Employee(const char name[], const char department[], unsigned age, double salary) {
	setName(name);
	setDepartment(department);
	setAge(age);
	setSalary(salary);
}

void Employee::toString() {
	cout << "Name: " << this->name << endl;
	cout << "Department: " << this->department << endl;
	cout << "Age: " << this->age << endl;
	cout << "Salary: " << this->salary << endl;
}

void Employee::destroyEmployee() {
	delete[] this->name;
	delete[] this->department;
}

Employee::~Employee() {
}