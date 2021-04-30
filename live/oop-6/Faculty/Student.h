#include<iostream>
#include<vector>

class Student {
private:
	unsigned FN;
	char* name;
	char* family;
	double OOP;
	double OOPpract;

public:
	Student(); // Constructor
	Student(const unsigned FN, const char name[], const char family[], const double OOP, const double OOPpract);
	~Student(); // Destructor
	Student(const Student& s); // Copy constructor
	Student(Student&& s) noexcept; // Move constructor
	Student& operator=(const Student& s);
	Student& operator=(Student&& s) noexcept;

	void setOOP(double mark);
	void setOOPpract(double mark);
	void toString();
	double getAverageGrade();
};

