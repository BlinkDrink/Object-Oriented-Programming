#pragma once
#include <iostream>

struct Book {
    char* title;
    char* author;
    char ISBN[14];
};

bool validateTitle(char title[]);

bool validateAuthor(char author[]);

bool validateISBN(char ISBN[]);

void initBook(Book* book, const char title[], const char author[], const char ISBN[]);

void add_book(Book* books, Book* book, unsigned* count, unsigned capacity);

void delete_book(Book* book);