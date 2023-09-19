//
// Created by Admin on 9/19/2023.
//

#ifndef DATA_H
#define DATA_H

#include <vector>
#include <string>

using namespace std;

// Define a Book class
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
void checkInBook(vector<Book>& library, const string& title);

#endif // DATA_H
