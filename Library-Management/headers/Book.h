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
    void deleteBook(string isbn);
    void modifyBook(string isbn);

    bool searchBook(const string& title, const string &username);

    bool bookIsAvailable(long int ISBN);
    void displayAllBooks();

//    void borrowBook(string username, long int ISBN);
    void returnBook(string username, long int ISBN);

    void addBook(string title, string author, string isbn, int copies);

    void borrowBook(const string &isbn, int copies, const string &username);

    bool stringCompare(const string& str1, const string& str2);

    void showBorrowedBooks(const string& targetUser);

    bool canBorrowBooks(const string& targetUser);

    string getTitleByISBN(const string& targetISBN);
};

#endif //LIBRARY_MANAGEMENT_BOOK_H
