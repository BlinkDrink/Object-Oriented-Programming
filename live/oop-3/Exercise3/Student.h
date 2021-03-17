#pragma once
#include "Grade.h"
#include <iostream>
struct Student {
    char* name;
    char* ID;
    unsigned facultyNumber;
    Grade grades[5];
};

Student* createStudent();

bool addStudent(Student* students, unsigned count);

void printStudent(Student* s);

void printStudentsBornInMarch(Student* students, unsigned count);

void printHighestPerformingStudent(Student* students, unsigned count);

void deleteStudent(Student* s);
