#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "Library.h"
#include <cstring>
#include <iostream>

using std::cin;
using std::cout;
/*
Да се направи структура Library, която ще съдържа списък от книги (n <= 1000).
Всяка книга се характеризира със заглавие, автор и ISBN номер. Да се реализират
следните функции:

да се добавя книга към списъка като характеристиките се прочитат от стандартния
вход. Заглавието трябва да е с главна буква без значение как го е въвел
потребителя. да се премахва книга от списъка по зададен ISBN номер да се
отпечатва броя на книгите
*/

void menu()
{
    cout << "\t\t MENU\n"
         << "1. Add book to the library\n"
         << "2.Remove book from the library by ISBN\n"
         << "3.Show books\n"
         << "4.Exit\n"
         << "Enter the desired command:";
}

int main()
{
    menu();
    unsigned cmd = 4;
    cin >> cmd;

    Library lib;
    lib.books = new Book[100];

    while (cmd != 4) {
        cin.ignore();
        switch (cmd) {
        case 1:
            addBook(&lib);
            break;
        case 2:
            removeBook(&lib);
            break;
        case 3:
            showBooks(lib);
            break;
        case 4:
            break;
        default:
            cout << "Invalid command!\n";
            break;
        }

        menu();
        cin >> cmd;
    }

    delete[] lib.books;

    return 0;
}
