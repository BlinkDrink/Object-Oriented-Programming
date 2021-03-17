#pragma once
#include <iostream>

struct Book {
    char* title;
    char* author;
    unsigned ISBN;
};

Book initBook();

void nullifyBook();

void setTitle(char* title, Book* book);

void setAuthor(char* author, Book* book);

void setISBN(unsigned ISBN, Book* book);
