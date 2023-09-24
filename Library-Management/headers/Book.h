//
// Created by Chairo on 9/22/2023.
//

#ifndef LIBRARY_MANAGEMENT_BOOK_H
#define LIBRARY_MANAGEMENT_BOOK_H

#include <vector>
#include <string>
#include "User.h"
using namespace std;

class Book: public User {
private:
    struct Books {
        string title;
        string author;
        string ISBN;
        int copies;

    };

    vector<Books> bookList;

public:


//    void initializeBooks(vector<Book> &library);

    void serializeBooks();
    void deserializeBooks();

    void addBook(string title, string author, long int ISBN, int copies);
    void deleteBook(string ISBN);
    void modifyBook(string ISBN);
    void searchBook();

    bool bookIsAvailable(long int ISBN);
    void displayAllBooks();

    void borrowBook(string username, long int ISBN);
    void returnBook(string username, long int ISBN);

    void addBook(string title, string author, string isbn, int copies);
};

#endif //LIBRARY_MANAGEMENT_BOOK_H
