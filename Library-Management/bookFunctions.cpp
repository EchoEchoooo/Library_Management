//
// Created by Chairo on 9/22/2023.
//

#include "headers/User.h"
#include "headers/Book.h"
#include <iostream>
#include <utility>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>
#include <algorithm>
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
    book.title = std::move(title);
    book.author = std::move(author);
    book.ISBN = std::move(isbn);
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

void Book::deleteBook(const string& isbn) {
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

void Book::modifyBook(const string& isbn) {
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

bool Book::stringCompare(const string& str1, const string& str2) {
    // Convert both strings to lowercase for comparison
    string lowerStr1 = str1;
    string lowerStr2 = str2;

    transform(lowerStr1.begin(), lowerStr1.end(), lowerStr1.begin(), ::tolower);
    transform(lowerStr2.begin(), lowerStr2.end(), lowerStr2.begin(), ::tolower);

    return lowerStr1 == lowerStr2;
}

//void Book::searchBook(const string& title) {
//
//    for (const Books& book : bookList) {
//        if (stringCompare(book.title, title)) {
//            cout << "BOOKFOUNDDDDDD!!: " << book.title << endl;
//        }
//    }
//
//}

bool Book::searchBook(const string& title, const string &username) {
    for (const Books& book : bookList) {
        if (stringCompare(book.title, title)) {
            cout << "\n\nBOOK FOUND: " << book.title << endl;

            borrowBook(book.ISBN, book.copies, username); // run the borrowBook function

            return true; // Book found, return true
        }
    }
    return false; // Book not found, return false
}

void Book::borrowBook(const string& isbn, int copies, const string& username) {
    char ch;
    cout << "Do you want to borrow? y/n :  ";
    cin >> ch;

    if (ch == 'y' || ch == 'Y') {
        if (copies == 0) {
            cout << "No Copies Available for this book";
        }

        if (canBorrowBooks(username)) {
            // Allow the user to borrow a book
            BorrowedBooks borrow;
            borrow.username = username;
            borrow.ISBN = isbn;

            // Get the current date
            time_t currentTime;
            struct tm* localTime;
            time(&currentTime);
            localTime = localtime(&currentTime);

            // Format the borrow date and return date
            char borrowDateStr[11];
            char returnDateStr[11];
            strftime(borrowDateStr, sizeof(borrowDateStr), "%Y-%m-%d", localTime);

            // Calculate the return date (2 weeks from the borrow date)
            localTime->tm_mday += 14; // Add 14 days
            mktime(localTime); // Normalize the date
            strftime(returnDateStr, sizeof(returnDateStr), "%Y-%m-%d", localTime);

            borrow.borrowDate = borrowDateStr;
            borrow.returnDate = returnDateStr;

            // Display the borrowing date and return date
            cout << "Borrowing Date: " << borrow.borrowDate << endl;
            cout << "Return Date: " << borrow.returnDate << endl;

            cout << "Confirm borrowing? y/n :  ";
            cin >> ch;

            if (ch == 'y' || ch == 'Y') {
                // Update the number of copies in the Library.txt file
                ifstream libraryFile("Library.txt");
                ofstream updatedLibraryFile("Library_updated.txt");
                string line;
                string title, author;

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
                                string bookIsbn = line.substr(0, pos);
                                line.erase(0, pos + 1); // Remove  '|'

                                // Parse copies
                                copies = stoi(line);

                                if (bookIsbn == isbn) {
                                    copies--;
                                    if (copies < 0) {
                                        copies   = 0; // Ensure non-negative copies
                                    }
                                }

                                // Modify the line with updated copies and write to the updated file
                                updatedLibraryFile << title << "|" << author << "|" << bookIsbn << "|" << copies << endl;
                            }
                        }
                    }
                }

                libraryFile.close();
                updatedLibraryFile.close();
                // Rename the updated file to replace the original Library.txt
                if (remove("Library.txt") == 0 && rename("Library_updated.txt", "Library.txt") == 0) {
                    // Successfully updated the Library.txt file
                    ofstream borrowBookFile("borrowedBooks.txt", ios::app);

                    if (borrowBookFile.is_open()) {
                        borrowBookFile << borrow.username << "|" << borrow.ISBN << "|" << borrow.borrowDate << "|" << borrow.returnDate << endl;
                    }

                    borrowedBooksList.push_back(borrow);
                    borrowBookFile.close();

                    cout << "Successfully Borrowed a Book!\n\n";
                } else {
                    cout << "Error updating the Library file." << endl;
                }
            } else {
                cout << "Borrowing canceled." << endl;
            }
        }
            else {
                cout << "Sorry, you have reached the maximum limit of 5 borrowed books." << endl;
            }
    }

    if (ch == 'n' || ch == 'N') {
        cout << "No";
    } else {
        cout << "\n";
    }
}

//void Book::borrowBook(const string& isbn, int copies, const string& username) {
//    char ch;
//    cout << "Do you want to borrow? y/n :  ";
//    cin >> ch;
//
//    if (ch == 'y' || ch == 'Y') {
//        if (copies == 0) {
//            cout << "No Copies Available for this book";
//        }
//
//        if (canBorrowBooks(username)) {
//            // Allow the user to borrow a book
//            BorrowedBooks borrow;
//            borrow.username = username;
//            borrow.ISBN = isbn;
//
//            // Get the current date
//            time_t currentTime;
//            struct tm* localTime;
//            time(&currentTime);
//            localTime = localtime(&currentTime);
//
//            // Format the borrow date and return date
//            char borrowDateStr[11];
//            char returnDateStr[11];
//            strftime(borrowDateStr, sizeof(borrowDateStr), "%Y-%m-%d", localTime);
//
//            // Calculate the return date (2 weeks from the borrow date)
//            localTime->tm_mday += 14; // Add 14 days
//            mktime(localTime); // Normalize the date
//
//            strftime(returnDateStr, sizeof(returnDateStr), "%Y-%m-%d", localTime);
//
//            borrow.borrowDate = borrowDateStr;
//            borrow.returnDate = returnDateStr;
//
//            // Display the borrowing date and return date
//            cout << "Borrowing Date: " << borrow.borrowDate << endl;
//            cout << "Return Date: " << borrow.returnDate << endl;
//
//            cout << "Confirm borrowing? y/n :  ";
//            cin >> ch;
//
//            if (ch == 'y' || ch == 'Y') {
//                ofstream borrowBookFile("borrowedBooks.txt", ios::app);
//
//                if (borrowBookFile.is_open()) {
//                    borrowBookFile << borrow.username << "|" << borrow.ISBN << "|" << borrow.borrowDate << "|" << borrow.returnDate << endl;
//                }
//
//                borrowedBooksList.push_back(borrow);
//                borrowBookFile.close();
//
//                cout << "Successfully Borrowed a Book!\n\n";
//            } else {
//                cout << "Borrowing canceled." << endl;
//            }
//        } else {
//            cout << "Sorry, you have reached the maximum limit of 5 borrowed books." << endl;
//        }
//    }
//
//    if (ch == 'n' || ch == 'N') {
//        cout << "No";
//    } else {
//        cout << "\n";
//    }
//}


string Book::getTitleByISBN(const string& targetISBN) {
    ifstream libraryFile("Library.txt");
    string line, title,isbn;

    while (getline(libraryFile, line)) {
        // Parse the line into title, author, ISBN, and copies
        size_t pos = line.find('|');

        if (pos != string::npos) {
            title = line.substr(0, pos);
            line.erase(0, pos + 1); // Remove '|'

            pos = line.find('|');

            if (pos != string::npos) {
                line.erase(0, pos + 1); // Remove '|'

                pos = line.find('|');

                if (pos != string::npos) {
                    isbn = line.substr(0, pos);
                    line.erase(0, pos + 1); // Remove '|'

                    // Check if the ISBN matches the targetISBN
                    if (isbn == targetISBN) {
                        // Return the corresponding title
                        return title;
                    }
                }
            }
        }
    }

    // If no matching ISBN is found, return an empty string
    return "";
}//string Book::getTitleByISBN(const string& targetISBN) {
//    ifstream libraryFile("library.txt");
//    string line, title, author, isbn, copiesStr;
//
//    while (getline(libraryFile, line)) {
//        // Parse the line into title, author, ISBN, and copies
//        size_t pos = line.find('|');
//
//        if (pos != string::npos) {
//            title = line.substr(0, pos);
//            line.erase(0, pos + 1); // Remove '|'
//
//            pos = line.find('|');
//
//            if (pos != string::npos) {
//                author = line.substr(0, pos);
//                line.erase(0, pos + 1); // Remove '|'
//
//                pos = line.find('|');
//
//                if (pos != string::npos) {
//                    isbn = line.substr(0, pos);
//                    line.erase(0, pos + 1); // Remove '|'
//
//                    copiesStr = line;
//
//                    // Check if the ISBN matches the targetISBN
//                    if (isbn == targetISBN) {
//                        // Return the corresponding title
//                        return title;
//                    }
//                }
//            }
//        }
//    }
//
//    // If no matching ISBN is found, return an empty string
//    return "";
//}

//void Book::showBorrowedBooks(const string& targetUser) {
//    ifstream borrowBooksFile("borrowedBooks.txt");
//    string line, user, isbn;
//
//    cout << "Searching for user: " << targetUser << endl;
//
//    while (getline(borrowBooksFile, line)) {
//        size_t pos = line.find('|');
//
//        if (pos != string::npos) {
//            user = line.substr(0, pos);
//
//            if (user == targetUser) {
//                isbn = line.substr(pos + 1); // Get the part after '|'
//
//                // Output the ISBN of the book borrowed by the target user
//                cout << "Book Title: " << getTitleByISBN(isbn) << endl;
//            }
//        }
//    }
//    borrowBooksFile.close();
//}
void Book::showBorrowedBooks(const string& targetUser) {
    ifstream borrowBooksFile("borrowedBooks.txt");
    string line, user, isbn, borrowDate, returnDate;

    cout << "Searching for user: " << targetUser << endl;

    while (getline(borrowBooksFile, line)) {
        size_t pos = line.find('|');

        if (pos != string::npos) {
            user = line.substr(0, pos);
            line.erase(0, pos + 1); // Remove '|'

            pos = line.find('|');

            if (pos != string::npos) {
                isbn = line.substr(0, pos);
                line.erase(0, pos + 1); // Remove '|'

                pos = line.find('|');

                if (pos != string::npos) {
                    borrowDate = line.substr(0, pos);
                    line.erase(0, pos + 1); // Remove '|'

                    returnDate = line; // The remaining part is the return date
                    if (user == targetUser) {
                        // Output the book title, borrow date, and return date
                        cout << "\n\nBook Title: " << getTitleByISBN(isbn) << endl;
                        cout << "Borrow Date: " << borrowDate << endl;
                        cout << "Return Date: " << returnDate << endl;
                    }
                }
            }
        }
    }
    borrowBooksFile.close();
}

bool Book::canBorrowBooks(const string& targetUser) {
    ifstream borrowBooksFile("borrowedBooks.txt");
    string line, user;
    int borrowedCount = 0;

    while (getline(borrowBooksFile, line)) {
        size_t pos = line.find('|');

        if (pos != string::npos) {
            user = line.substr(0, pos);

            if (user == targetUser) {
                borrowedCount++;
            }
        }
    }
    borrowBooksFile.close();

    // Check if the user has borrowed 5 or fewer books
    if (borrowedCount < 5) {
        return true; // User can borrow more books
    } else {
        return false; // User has reached the limit
    }
}


