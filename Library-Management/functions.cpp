//
// Created by Admin on 9/19/2023.
//





#include "data.h"
#include <iostream>

using namespace std; // Only added here, not in the header file

// Function to display the main menu
void displayMainMenu() {
    cout << "===================================" << endl;
    cout << "    Library Management System" << endl;
    cout << "===================================" << endl;
    cout << "[1] Search For a book" << endl;
    cout << "[2] Check-in a book" << endl;
    cout << "[3] Check-out a book" << endl;
    cout << "[4] Inventory" << endl;
    cout << "[5] Exit" << endl;
}

// Function to search for a book by title
void searchBook(const vector<Book>& library, const string& title) {
    for (const Book& book : library) {
        if (book.title == title) {
            cout << "Book found:" << endl;
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << (book.isAvailable ? "Status: Checked Out" : "Status: Available") << endl;
            return;
        }
    }
    cout << "Book not found." << endl;
}

// Function to check out a book by title
void checkOutBook(vector<Book>& library, const string& title) {
    for (Book& book : library) {
        if (book.title == title) {
            if (!book.isAvailable) {
                book.isAvailable = true;
                cout << "Book checked out successfully." << endl;
                return;
            } else {
                cout << "This book is already checked out." << endl;
                return;
            }
        }
    }
    cout << "Book not found." << endl;
}

// Function to check in a book by title
void checkInBook(vector<Book>& library, const string& title) {
    for (Book& book : library) {
        if (book.title == title) {
            if (book.isAvailable) {
                book.isAvailable = false;
                cout << "Book checked in successfully." << endl;
                return;
            } else {
                cout << "This book is not checked out." << endl;
                return;
            }
        }
    }
    cout << "Book not found." << endl;
}
