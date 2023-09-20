//
// Created by Admin on 9/19/2023.
//

#ifndef DATA_H
#define DATA_H

#include <vector>
#include <string>

using namespace std;

class User {
protected:
    struct Users {
        //string firstName, middleName, lastName;
        string username;
        string password;
        //string address;
        //int contactNo;
        bool isAdmin;
    };
    vector<Users> usersList;

    struct BorrowedBooks {
        string username;
        vector<int> ISBNs;
    };
    vector<BorrowedBooks> borrowedBooksList;

public:
    void serializeUsers();
    void deserializeUsers();
    void login(string username, string password);
    bool adminLogin(); //for temporary use
    bool userExists(string username);
    void addUser(string username, string password, bool isAdmin);
    void displayAnalytics();
    void displayAllUsers();
    void searchUser(string username);
    void modifyUser(string username, string password);
};

class Book: public User {
private:
    struct Books {
        string title;
        string author;
        long int ISBN;
        int copies;
    };
    vector<Books> booksList;

public:
    void serializeBooks();
    void deserializeBooks();
    void addBook(string title, string author, long int ISBN, int copies);
    void deleteBook(long int ISBN);
    void modifyBook(long int ISBN);
    void searchBook();
    bool bookIsAvailable(long int ISBN);
    void displayAllBooks();
    void borrowBook(string username, long int ISBN);
    void returnBook(string username, long int ISBN);
};

/*// Define a Book class
class Book {
public:
    string title;
    string author;
    int ISBN;
    bool isAvailable;
    int copies;

    // Constructor
    Book(string t, string a, int isbn, int c)
            : title(t), author(a), ISBN(isbn), isAvailable(true), copies(c) {}
};

// Function declarations
void displayMainMenu();
void searchBook(const vector<Book>& library, const string& title);
void checkOutBook(vector<Book>& library, const string& title);
void checkInBook(vector<Book>& library, const string& title);*/


#endif // DATA_H
