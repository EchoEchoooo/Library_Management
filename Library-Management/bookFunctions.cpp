//
// Created by Chairo on 9/22/2023.
//

#include "headers/User.h"
#include "headers/Book.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void Book::serializeBooks() { //Write to admins text file
    ofstream bookFile("Library.txt");

    if(bookFile.is_open()) {
        for (auto & i : bookList) {
            bookFile << i.title << "|" << i.author << "|" << i.ISBN << "|" << i.copies << endl;
        }
    }

    bookFile.close();
}
void Book::deserializeBooks() { // Read from admins text file
    ifstream libraryFile("Library.txt");
    string line, title, author, isbn;
    int copies;

    while (getline(libraryFile, line)) {
        size_t pos = line.find('|');

        if (pos != string::npos) {
            title = line.substr(0, pos);
            line.erase(0, pos + 1); // Remove  '|'

            pos = line.find('|');

            if (pos != string::npos) {
                author = line.substr(0, pos);
                line.erase(0, pos + 1); // Remove  '|'

                // Parse ISBN from the remaining line
                pos = line.find('|');
                if (pos != string::npos) {
                    isbn = line.substr(0, pos);
                    line.erase(0, pos + 1); // Remove  '|'
                }

                // Parse copies string to int
                copies = stoi(line);

                // run the function & add the book inside the book vector
                addBook(title,author,isbn,copies);
            }
        }
    }
    libraryFile.close();
}
void Book::addBook(string title, string author, string isbn, int copies) {
    Books book; // declare an object book

    // pass the values inside the objects members
    book.title = title;
    book.author = author;
    book.ISBN = isbn;
    book.copies = copies;

    // push contents inside the vector "bookList"
    bookList.push_back((book));
}

void Book::displayAllBooks() { //display all the users in the vector
    if (bookList.empty())
        exit(1);

    else {
        for (auto & i : bookList) {
            cout << "\t\t[" << i.ISBN << "]\n";
            cout << "Title: " << i.title << "\nAuthor: " << i.author
            << endl << "Copies: " << i.copies << endl << endl;
        }
    }
}

void Book::deleteBook(string isbn) {
    if (bookList.empty())
        cout << "\n\tThere are no books\n";

    else {
        for (auto i = bookList.begin(); i != bookList.end(); ++i) {
            if (i->ISBN == isbn) {
                bookList.erase(i);
                cout << endl << isbn << " has been successfully deleted\n";
                break;
            }

            else
                cout << "\n\tBook not found";
        }
    }
}

void Book::modifyBook(string isbn) {
    if (bookList.empty()) {
        cout << "\n\tThere are no books to modify.\n";
        return;
    }

    bool found = false;
    for (auto &book : bookList) {
        if (book.ISBN == isbn) {
            found = true;
            cout << "\n\tBook found. Please enter the new information:\n";

            string newTitle, newAuthor;
            int newCopies;

            cout << "\n\tEnter new title: ";
            cin.ignore();
            getline(cin, newTitle);

            cout << "\n\tEnter new author: ";
            getline(cin, newAuthor);

            cout << "\n\tEnter new number of copies: ";
            cin >> newCopies;

            book.title = newTitle;
            book.author = newAuthor;
            book.copies = newCopies;

            cout << "\n\tBook information updated successfully.\n";
            break;
        }
    }

    if (!found) {
        cout << "\n\tBook with ISBN " << isbn << " not found.\n";
    }
}



