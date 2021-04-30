#include "Employee.h"

class Company {
private:
	Employee* employees;
	unsigned size;
	unsigned currCapacity = 1;
	const unsigned capacity = 1000;

	void resizeEmployees();
	void shiftEmployees(unsigned index);
public:
	Company();

	void addEmployee(Employee* employee);
	bool removeEmployee(Employee* employee);
	bool isEmpty();
	void sortEmployeesByName();

	~Company();
};