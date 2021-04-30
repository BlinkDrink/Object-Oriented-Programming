#include<iostream>
#include<cstring>

class Employee {
private:
	char* name;
	char* department;
	unsigned age;
	double salary; // field

public:
	Employee();
	Employee(const char name[], const char department[], unsigned age, double salary);

	void setName(const char name[]); // method
	void setDepartment(const char department[]);
	void setAge(unsigned age);
	void setSalary(double salary);

	const char* getName() const;
	const char* getDepartment() const;
	const unsigned getAge() const;
	const double getSalary() const;

	bool areEqual(Employee* e2);

	void toString();

	void destroyEmployee();
	~Employee();
};


