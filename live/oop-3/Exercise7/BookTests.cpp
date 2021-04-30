#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "Book.h"
#include "catch.hpp"
#include <cassert>

using std::strcmp;

TEST_CASE("add_book should add books accordingly", "[add_book]")
{
    Book* books = new Book[5];
    unsigned capacity = 5;
    unsigned count = 0;
    Book b;

    initBook(&b, "Chavdar Voivoda", "Pesho", "1234567890123");
    add_book(books, &b, &count, capacity);

    SECTION("after adding book, count of the list should be incremented")
    {

        REQUIRE(count == 1);
    }

    SECTION("after adding book, properties of book should be the same as the added one")
    {
        REQUIRE(strcmp(b.author, "Pesho") == 0);
        REQUIRE(strcmp(b.title, "Chavdar Voivoda") == 0);
        REQUIRE(strcmp(b.ISBN, "1234567890123") == 0);
    }

    for (unsigned i = 0; i < count; i++) {
        delete_book(&books[i]);
    }

    delete[] books;
}