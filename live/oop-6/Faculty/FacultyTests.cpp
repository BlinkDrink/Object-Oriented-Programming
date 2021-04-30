//#define CATCH_CONFIG_MAIN 
#include "Faculty.h"
#include<cassert>

int main() {
	Faculty fmi;

	Student p(45811, "Petko", "Petkov", 5, 6);
	Student b(45809, "Boyan", "Todorov", 6, 6);
	Student a(12345, "Albena", "Todorova", 2, 2);
	Student v(54321, "Vladimir", "Todorov", 2.5, 2.5);

	Student p2 = Student(450, "Ala", "Bala", 5, 5);


	fmi.setFacultyName("FMI");
	fmi.setPrincipal("Parvan Evtimov Parvanov");
	fmi.addStudent(&p);
	fmi.addStudent(&b);
	fmi.addStudent(&a);
	fmi.addStudent(&v);
	fmi.removeStudentsWithF();

	fmi.printStudents();

	return 0;
}