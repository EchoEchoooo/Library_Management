#ifndef LIBRARY_MANAGEMENT_BOOK_H
#define LIBRARY_MANAGEMENT_BOOK_H

#include <vector>
#include <string>
#include "User.h"

using namespace std;

class Book : public User {
private:
    struct Books {
        string title;
        string author;
        string ISBN;
        int copies;

    };
    vector<Books> bookList;
public:

    void serializeBooks();

    void deserializeBooks();

    void deleteBook(const string &isbn);

    void modifyBook(const string &isbn);

    bool searchBook(const string &title, const string &username);

    void displayAllBooks();

    void returnBook(string username, string isbn);

    void addBook(string title, string author, string isbn, int copies);

    void borrowBook(const string &isbn, int copies, const string &username);

    bool stringCompare(const string &str1, const string &str2);

    void showBorrowedBooks(const string &targetUser);

    bool canBorrowBooks(const string &targetUser);

    string getTitleByISBN(const string &targetISBN);
};

#endif //LIBRARY_MANAGEMENT_BOOK_H
