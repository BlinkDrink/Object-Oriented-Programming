#include "Student.h"

using std::vector;

class Faculty {
private:
	char* facultyName;
	char* principal;
	vector<Student> students;
public:
	Faculty();
	~Faculty();

	void addStudent(const Student* s);
	void setFacultyName(const char name[]);
	void setPrincipal(const char principal[]);
	void printStudents();
	void printAverageGrades();
	void removeStudentsWithF();
	void expelStudent(unsigned index);
};