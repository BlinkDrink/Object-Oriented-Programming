#include "Book.h"
#include <cstring>

bool validateTitle(const char title[])
{
    if (strlen(title) > 256) {
        return false;
    }

    return true;
}

bool validateAuthor(const char author[])
{
    if (strlen(author) > 256) {
        return false;
    }

    return true;
}

bool validateISBN(const char ISBN[])
{
    if (strlen(ISBN) != 13) {
        return false;
    }

    return true;
}

void initBook(Book* book, const char title[], const char author[], const char ISBN[])
{
    if (!validateTitle(title)) {
        return;
    }

    if (!validateAuthor(author)) {
        return;
    }

    if (!validateISBN(ISBN)) {
        return;
    }

    unsigned titleLen = strlen(title);
    unsigned authorLen = strlen(title);

    book->title = new char[titleLen + 1];
    if (!book->title) {
        return;
    }

    book->author = new char[authorLen + 1];
    if (!book->author) {
        return;
    }

    strcpy_s(book->title, sizeof(char) * (titleLen + 1), title);
    strcpy_s(book->author, sizeof(char) * (authorLen + 1), author);

    for (unsigned i = 0; i < 14; i++) {
        book->ISBN[i] = ISBN[i];
    }
}

void resizeArr(Book* books, unsigned* count)
{
    Book* newBookArr = new Book[*count * 2];
    if (!newBookArr) {
        return;
    }

    for (unsigned i = 0; i < *count; i++) {
        newBookArr[i] = books[i];
    }

    delete[] books;
    books = newBookArr;
    *count *= 2;
}

void add_book(Book* books, Book* book, unsigned* count, unsigned capacity)
{
    if (*count == capacity) {
        resizeArr(books, count);
    }

    books[*count] = *book;
    (*count)++;
}

void delete_book(Book* book)
{
    delete[] book->title;
    delete[] book->author;
}