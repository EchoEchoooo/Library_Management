#include <iostream>
#include <vector>
#include <string>
#include "data.h"

using namespace std;

int main() {
    // Create a vector to store the library books
    vector<Book> library;

    int choice;
    string title;

    do {
        // Display the main menu
        displayMainMenu();

        // Get user's choice
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Search for a book
                cout << "Enter the title of the book to search: ";
                cin.ignore();
                getline(cin, title);
                searchBook(library, title);
                break;
            case 2:
                // Check-in a book
                cout << "Enter the title of the book to check in: ";
                cin.ignore();
                getline(cin, title);
                checkInBook(library, title);
                break;
            case 3:
                // Check-out a book
                cout << "Enter the title of the book to check out: ";
                cin.ignore();
                getline(cin, title);
                checkOutBook(library, title);
                break;
            case 4:
                // Display the inventory
                cout << "Library Inventory:" << endl;
                for (const Book& book : library) {
                    cout << "Title: " << book.title << " | Author: " << book.author
                         << " | Status: " << (book.isAvailable ? "Checked Out" : "Available") << endl;
                }
                break;
            case 5:
                // Exit the program
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 5);

    return 0;
}
