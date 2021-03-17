#pragma once
#include "Book.h"
#include <iostream>

struct Library {
    const unsigned capacity = 1000;
    unsigned currentNumOfBooks = 0;
    Book* books;
};

void addBook(Library* lib);

Book* findBookByISBN(Book* books, unsigned ISBN, unsigned currentNumOfBooks);

void removeBook(Library* lib);

void printBook(char* title, char* author, unsigned ISBN, unsigned index);

void showBooks(Library lib);
