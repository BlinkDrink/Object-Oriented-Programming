#include "Library.h"
#include <cstring>

using std::cin;
using std::cout;

void addBook(Library* lib)
{
    if (lib->currentNumOfBooks == 1000) {
        cout << "Library is full!";
        return;
    }

    Book book = initBook();

    lib->currentNumOfBooks++;
    char buffer[100];
    unsigned ISBN;

    // Title input
    cout << "Enter the name of the book:";
    cin.getline(buffer, 100);
    setTitle(buffer, &book);

    // Author input
    cout << "\nEnter the author of the book:";
    cin.getline(buffer, 100);
    setAuthor(buffer, &book);

    // ISBN input
    cout << "\nEnter the ISBN of the book:";
    cin >> ISBN;
    setISBN(ISBN, &book);

    lib->books[lib->currentNumOfBooks - 1] = book;
}

Book* findBookByISBN(Book* books, unsigned ISBN, unsigned currentNumOfBooks)
{
    for (unsigned i = 0; i < currentNumOfBooks; i++) {
        if (books[i].ISBN == ISBN) {
            return &books[i];
        }
    }

    return nullptr;
}

void removeBook(Library* lib)
{
    unsigned ISBN;
    cin >> ISBN;
    if (!ISBN) {
        cout << "Invalid ISBN!";
        return;
    }

    Book* book = findBookByISBN(lib->books, ISBN, lib->currentNumOfBooks);
    if (!book) {
        cout << "Book not found!";
    }

    book = nullptr;
}

void printBook(char* title, char* author, unsigned ISBN, unsigned index)
{
    cout << '\t' << index << '.' << title << "\n\t"
         << author << "\n\t"
         << ISBN << "\n";
}

void showBooks(Library lib)
{
    unsigned currentNumBooks = lib.currentNumOfBooks;
    for (unsigned i = 0; i < currentNumBooks; i++) {
        printBook(lib.books[i].title, lib.books[i].author, lib.books[i].ISBN, i + 1);
    }
}