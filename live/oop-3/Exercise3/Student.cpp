#include "Student.h"
#include <cstring>

using std::cin;
using std::cout;
using std::strcpy;
using std::strlen;

bool isLetter(char l)
{
    return (l >= 97 && l <= 122) || (l >= 65 && l <= 90);
}

bool isCapital(char l)
{
    return (l >= 65 && l <= 90);
}

void capitalizeStartingLetters(char* name)
{
    while (*name) {
        while (!isLetter(*name)) {
            name++;
        }

        if (!isCapital(*name)) {
            *name -= 32;
        }

        while (isLetter(*name)) {
            name++;
        }
    }
}

unsigned trySetName(char* name, Student* s)
{
    cout << "Enter student's full name: ";
    cin.getline(name, 100);
    cout << '\n';

    unsigned nameLen = strlen(name);
    s->name = new char[nameLen + 1];
    if (!s->name) {
        return 0;
    }

    capitalizeStartingLetters(name);
    strcpy_s(s->name, (nameLen + 1) * sizeof(char), name);

    s->name[nameLen] = '\0';

    return 1;
}

unsigned trySetID(char* ID, Student* s)
{
    cout << "Enter student's ID: ";
    cin.getline(ID, 100);
    cout << '\n';

    unsigned IDLen = strlen(ID);
    if (IDLen != 10) {
        cout << "Incorrect ID!\n";
        return 0;
    }

    s->ID = new char[IDLen + 1];
    if (!s->ID) {
        return 0;
    }

    strcpy_s(s->ID, (IDLen + 1) * sizeof(char), ID);
    s->ID[IDLen] = '\0';

    return 1;
}

unsigned trySetFacultyNum(unsigned facultyNum, Student* s)
{
    cout << "Enter student's faculty number: ";
    cin >> facultyNum;
    cout << '\n';

    if (facultyNum < 100000 || facultyNum > 999999) {
        cout << "Incorrect faculty number!\n";
        return 0;
    }
    s->facultyNumber = facultyNum;

    return 1;
}

unsigned trySetGrades(char* subject, Student* s)
{
    for (unsigned i = 0; i < 5; i++) {
        cin.ignore();
        cout << "Enter subject #" << i << ": ";
        cin.getline(subject, 100);
        cout << '\n';

        unsigned subjectLen = strlen(subject);
        s->grades[i].subject = new char[subjectLen + 1];
        if (!s->grades[i].subject) {
            return 0;
        }

        strcpy_s(s->grades[i].subject, (subjectLen + 1) * sizeof(char), subject);
        s->grades[i].subject[subjectLen] = '\0';

        cout << "Enter subject #" << i << " grade: ";
        cin >> s->grades[i].grade;
        cout << '\n';
    }
}

Student* createStudent()
{
    Student s;
    unsigned facultyNum = 0;
    char buffer[100];

    if (trySetName(buffer, &s) == 0) {
        return nullptr;
    };

    if (trySetID(buffer, &s) == 0) {
        return nullptr;
    }

    if (trySetFacultyNum(facultyNum, &s) == 0) {
        return nullptr;
    }

    if (trySetGrades(buffer, &s) == 0) {
        return nullptr;
    }

    return &s;
}

bool addStudent(Student* students, unsigned count)
{
    Student* s = createStudent();

    if (!s) {
        cout << "Couldn't create student!\n";
        return false;
    }

    students[count] = *s;
    return true;
}

double getAveragePerformance(Student* s)
{
    double avg = 0;
    for (unsigned i = 0; i < 5; i++) {
        avg += s->grades[i].grade;
    }

    return avg / 5;
}

void printStudent(Student* s)
{
    double avg = getAveragePerformance(s);

    cout << "Full name: " << s->name << "| Average performance: " << avg << '\n';
}

bool isBornInMarch(char* ID)
{
    if (ID[3] == '3') {
        return true;
    }

    return false;
}

void printStudentsBornInMarch(Student* students, unsigned count)
{
    for (unsigned i = 0; i < count; i++) {
        if (isBornInMarch(students[i].ID)) {
            printStudent(&students[i]);
        }
    }
}

void printHighestPerformingStudent(Student* students, unsigned count)
{
    Student* s = nullptr;
    double highestScore = 0;
    for (unsigned i = 0; i < count; i++) {
        double avg = getAveragePerformance(&students[i]);
        if (highestScore < avg) {
            highestScore = avg;
            s = &students[i];
        }
    }

    printStudent(s);
}

void deleteStudent(Student* s)
{
    delete[] s->name;
    delete[] s->ID;

    for (unsigned i = 0; i < 5; i++) {
        delete[] s->grades[i].subject;
    }
}
