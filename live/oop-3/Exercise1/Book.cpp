#include "Book.h"
using std::strlen;

Book initBook()
{
    Book book;

    book.title = new char[100];
    book.author = new char[100];

    return book;
}

void setTitle(char* title, Book* book)
{
    book->title = title;
}

void setAuthor(char* author, Book* book)
{
    book->author = author;
}

void setISBN(unsigned ISBN, Book* book)
{
    book->ISBN = ISBN;
}
