#include "Student.h"
using std::cin;
using std::cout;

void menu()
{
    cout << "\n\n\tMENU\n";
    cout << "1.Add a student\n";
    cout << "2.Show average performance of students born in March\n";
    cout << "3.Show the student with highest performance\n";
    cout << "4.Exit\n";
    cout << "--Enter an option: ";
}

void resizeArr(Student* students, unsigned* currentMax, unsigned currentCount)
{
    if (currentCount == *currentMax) {
        Student* newStudentsArr = new Student[currentCount * 2];

        for (unsigned i = 0; i < currentCount; i++) {
            newStudentsArr[i] = students[i];
        }

        //delete[] students;

        *currentMax = currentCount * 2;
        students = newStudentsArr;
    }
}

int main()
{
    Student* students = new Student[1];
    unsigned currentMax = 1;
    unsigned currentCount = 0;

    menu();
    unsigned cmd = 4;
    cin >> cmd;

    while (cmd != 4) {
        cin.ignore();
        switch (cmd) {
        case 1:
            resizeArr(students, &currentMax, currentCount);
            if (addStudent(students, currentCount)) {
                currentCount++;
            }
            break;
        case 2:
            printStudentsBornInMarch(students, currentCount);
            break;
        case 3:
            printHighestPerformingStudent(students, currentCount);
            break;
        case 4:
            break;
        default:
            break;
        }

        menu();
        cin >> cmd;
    }

    for (unsigned i = 0; i < currentCount; i++) {
        deleteStudent(&students[i]);
    }

    delete[] students;

    return 0;
}