#include "Faculty.h"

using std::cout;

Faculty::Faculty() {
	this->facultyName = nullptr;
	this->principal = nullptr;
}

Faculty::~Faculty() {
	delete[] this->facultyName;
	delete[] this->principal;
}

void Faculty::addStudent(const Student* s) {
	this->students.push_back(*s);
}

void Faculty::setFacultyName(const char name[]) {
	this->facultyName = new char[strlen(name) + 1];
	strcpy_s(this->facultyName, sizeof(char) * (strlen(name) + 1), name);
}

void Faculty::setPrincipal(const char principal[]) {
	this->principal = new char[strlen(principal) + 1];
	strcpy_s(this->principal, sizeof(char) * (strlen(principal) + 1), principal);
}

void Faculty::printStudents() {
	unsigned size = this->students.size();
	for (unsigned i = 0; i < size; i++)
	{
		this->students[i].toString();
	}
}

void Faculty::printAverageGrades() {
	unsigned size = this->students.size();
	for (unsigned i = 0; i < size; i++)
	{
		this->students[i].toString();
		cout << "Average marks: " << this->students[i].getAverageGrade();
	}
}

void Faculty::expelStudent(unsigned index) {
	this->students.erase(this->students.begin() + index);
}

void Faculty::removeStudentsWithF() {
	for (unsigned i = 0; i < this->students.size(); i++)
	{
		if (this->students[i].getAverageGrade() < 3) {
			this->expelStudent(i);
			i--;
		}
	}
}
