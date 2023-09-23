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




