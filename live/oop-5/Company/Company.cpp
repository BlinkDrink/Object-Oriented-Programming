#include "Company.h"

using std::cout;
using std::swap;

Company::Company() {
	this->employees = new Employee[this->currCapacity];
	this->size = 0;
}

void Company::resizeEmployees() {
	Employee* newEmployees = new Employee[this->currCapacity * 2];

	if (!newEmployees)
	{
		cout << "There was an error during resizing!";
		return;
	}

	for (unsigned i = 0; i < this->size; i++)
	{
		newEmployees[i] = this->employees[i];
		//this->employees[i] = nullptr;
	}

	delete[] this->employees;
	this->employees = newEmployees;
	this->currCapacity *= 2;
}

void Company::addEmployee(Employee* employee) {
	if (this->size == this->capacity)
	{
		cout << "No more than 1000 employees allowed!";
		return;
	}

	if (this->size == this->currCapacity)
	{
		resizeEmployees();
	}

	Employee* e = &(this->employees[this->size]);

	e->setName(employee->getName());
	e->setDepartment(employee->getDepartment());
	e->setAge(employee->getAge());
	e->setSalary(employee->getSalary());

	this->size++;
}

void Company::shiftEmployees(unsigned index) {
	for (unsigned i = index; i < this->size - 1; i++)
	{
		swap(this->employees[i], this->employees[i + 1]);
	}
}

bool Company::removeEmployee(Employee* employee) {
	for (unsigned i = 0; i < this->size; i++)
	{
		if (this->employees[i].areEqual(employee))
		{
			this->employees[i].destroyEmployee();
			this->shiftEmployees(i);
			this->size--;
			return true;
		}
	}

	return false;
}

bool Company::isEmpty() {
	return this->size != 0;
}

void Company::sortEmployeesByName() {
	for (unsigned i = 0; i < this->size - 1; i++) {
		for (unsigned j = i; j < this->size; j++) {
			if (strcmp(this->employees[i].getName(), this->employees[j].getName()) > 0) {
				swap(this->employees[i], this->employees[j]);
			}
		}
	}
}

Company::~Company() {
	for (unsigned i = 0; i < this->size; i++)
	{
		this->employees[i].destroyEmployee();
	}
	delete[] this->employees;
}
