#include "Student.h"
#include<cstring>

using std::out_of_range;
using std::cout;

Student::Student() {
	this->FN = 0;
	this->name = nullptr;
	this->family = nullptr;
	this->OOP = 0;
	this->OOPpract = 0;
}

Student::Student(const unsigned FN, const char name[], const char family[], const double OOP, const double OOPpract) {
	this->FN = FN;

	unsigned sNameLen = strlen(name);
	unsigned sFamilyLen = strlen(family);

	this->name = new char[sNameLen + 1];
	strcpy_s(this->name, sizeof(char) * (sNameLen + 1), name);

	this->family = new char[sFamilyLen + 1];
	strcpy_s(this->family, sizeof(char) * (sFamilyLen + 1), family);

	this->OOP = OOP;
	this->OOPpract = OOPpract;
}


Student::~Student() {
	delete[] this->name;
	delete[] this->family;
}

// Copy constructor
Student::Student(const Student& s) {
	if (&s == nullptr)
	{
		return;
	}

	this->FN = s.FN;

	unsigned sNameLen = strlen(s.name);
	unsigned sFamilyLen = strlen(s.family);

	this->name = new char[sNameLen + 1];
	strcpy_s(this->name, sizeof(char) * (sNameLen + 1), s.name);

	this->family = new char[sFamilyLen + 1];
	strcpy_s(this->family, sizeof(char) * (sFamilyLen + 1), s.family);

	this->OOP = s.OOP;
	this->OOPpract = s.OOPpract;
}

// Move constructor
Student::Student(Student&& s) noexcept {
	this->FN = s.FN;
	s.FN = 0;

	this->name = s.name;
	s.name = nullptr;

	this->family = s.family;
	s.family = nullptr;

	this->OOP = s.OOP;
	s.OOP = 0;

	this->OOPpract = s.OOPpract;
	s.OOPpract = 0;
}

// Copy assignment
Student& Student::operator=(const Student& s) {
	if (this == &s)
	{
		return *this;
	}

	this->FN = s.FN;

	unsigned sNameLen = strlen(s.name);
	unsigned sFamilyLen = strlen(s.family);

	this->name = new char[sNameLen + 1];
	strcpy_s(this->name, sizeof(char) * (sNameLen + 1), s.name);

	this->family = new char[sFamilyLen + 1];
	strcpy_s(this->family, sizeof(char) * (sFamilyLen + 1), s.family);

	this->OOP = s.OOP;
	this->OOPpract = s.OOPpract;

	return *this;
}

// Move assignment
Student& Student::operator=(Student&& s) noexcept {
	if (this == &s)
	{
		return *this;
	}

	this->FN = s.FN;
	s.FN = 0;

	this->name = s.name;
	s.name = nullptr;

	this->family = s.family;
	s.family = nullptr;

	this->OOP = s.OOP;
	s.OOP = 0;

	this->OOPpract = s.OOPpract;
	s.OOPpract = 0;

	return *this;
}

void Student::setOOP(double mark) {
	if (mark < 2 || mark > 6)
	{
		throw out_of_range("Mark should be between 2 and 6!");
	}

	this->OOP = mark;
}

void Student::setOOPpract(double mark) {
	if (mark < 2 || mark > 6)
	{
		throw out_of_range("Mark should be between 2 and 6!");
	}

	this->OOPpract = mark;
}

void Student::toString() {
	cout << "\nName: " << this->name << ' ' << this->family;
}

double Student::getAverageGrade() {
	return (this->OOP + this->OOPpract) / 2;
}

