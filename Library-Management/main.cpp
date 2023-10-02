#include <iostream>
#include <string>
#include <iomanip>
#include "headers/User.h"
#include "headers/Book.h"

using namespace std;

int main() {
    User user;
    Admin admin;
    Book book;

    user.deserializeUsers();
    admin.deserializeUsers();
    book.deserializeBooks();

    string title, author, isbn;
    int copies;

    string username, password, contactNo;


    char ch;

    do {
        system("CLS");
        cout << "\n\n";
        cout << setw(50) << " Choose an account";
        cout << "\n\n\t1. Student";
        cout << "\n\n\t2. Admin";
        cout << "\n\n\t3. Exit";
        cout << "\n\n\tChoose an option: ";
        cin >> ch;
        switch (ch) {
            case '1':
                cout << "\tEnter Username: ";
                cin >> username;
                cout << "\tEnter Password: ";
                cin >> password;

                if (user.loginUser(username, password)) {
                    cout << "\n\tStudent login successful.\n\n";
                    int userChoice;

                    do {
                        cout << setw(50) << "S T U D E N T  M E N U" << endl;
                        cout << "\n\t[1] Borrow Book";
                        cout << "\n\t[2] My Borrowed Books";
                        cout << "\n\t[3] Return Book/s";
                        cout << "\n\t[4] Display Library";
                        cout << "\n\t[5] Modify Account";
                        cout << "\n\t[6] Exit";
                        cout << "\n\n\tEnter your Choice:";
                        cin >> userChoice;
                        string userInput;
                        switch (userChoice) {
                            case 1:
                                cout << "[B O O K  S E A R C H] \n";
                                cout << "0 to exit\n\n";
                                cout << "Search a Book: ";
                                cin.ignore();
                                getline(cin, userInput);
                                if (book.searchBook(userInput, username)) {
                                    // book found
                                } else {
                                    cout << "The Book you searched is not available.\n\n";
                                }
                                break;
                            case 2:
                                book.showBorrowedBooks(username);
                                break;
                            case 3:
                                cout << "\tEnter ISBN: ";
                                cin >> isbn;
                                book.returnBook(username, isbn);
                                break;
                            case 4:
                                book.displayAllBooks();
                                break;
                            case 5:
                                user.modifyUser(username);
                                user.serializeUsers();
                                break;
                            case 6:
                                break;
                            default:
                                cout << "Error.";
                        }
                    } while (userChoice != 6);
                } else
                    cout << "\nIncorrect username or password\n";

                break;
            case '2':
                cout << "\tEnter Username: ";
                cin >> username;
                cout << "\tEnter Password: ";
                cin >> password;

                if (admin.loginUser(username, password)) {
                    cout << "\n\tAdmin login successful.\n";
                    int adminChoice;
                    do {
                        cout << "\n\n";
                        cout << setw(50) << " Admin Menu";
                        cout << "\n\n\t[1] Add books";
                        cout << "\n\n\t[2] Modify books";
                        cout << "\n\n\t[3] Delete books";
                        cout << "\n\n\t[4] Display all books";
                        cout << "\n\n\t[5] Create student account";
                        cout << "\n\n\t[6] Modify student account";
                        cout << "\n\n\t[7] Delete student account";
                        cout << "\n\n\t[8] Display student accounts";
                        cout << "\n\n\t[9] Back to main menu";
                        cout << "\n\n\tChoose an option: ";
                        cin >> adminChoice;
                        switch (adminChoice) {
                            case 1: //addBook();
                                cout << "Enter Title: ";
                                getline(cin, title);
                                cin.ignore();

                                cout << "\nEnter Author: ";
                                getline(cin, author);
                                cin.ignore();

                                cout << "Enter ISBN: ";
                                cin >> isbn;

                                cout << "Enter Copies: ";
                                cin >> copies;

                                book.addBook(title, author, isbn, copies);
                                book.serializeBooks();
                                break;
                            case 2: // modifyBook
                                cout << "Enter ISBN of the book to modify: ";
                                cin >> isbn;
                                book.modifyBook(isbn);
                                book.serializeBooks();
                                break;
                            case 3: //deleteBook
                                cout << "Enter ISBN: ";
                                cin >> isbn;
                                book.deleteBook(isbn);
                                break;
                            case 4: //displayAllBooks
                                book.displayAllBooks();
                                break;
                            case 5: //createStudentAccount
                                cout << "Enter Username: ";
                                cin >> username;
                                cout << "Enter Password: ";
                                cin >> password;
                                cout << "Enter Contact No: ";
                                cin >> contactNo;
                                user.addUser(username, password, contactNo);
                                user.serializeUsers();
                                system("pause");
                                break;
                            case 6: //modifyStudentAccount
                                cout << "Enter account username to modifyL: ";
                                cin >> username;

                                user.modifyUser(username);
                                break;
                            case 7: //deleteStudentAccount
                                cout << "\tEnter Username: ";
                                cin >> username;
                                admin.deleteUser(username);
                                break;
                            case 8: //displayStudentAccounts
                                user.displayAllUsers();
                                break;
                            case 9:
                                cout << "\n\tBack to main menu.\n";
                                break;
                            default:
                                cout << "\n\tInvalid Choice! ";
                                system("pause");
                        }
                    } while (adminChoice != 9);
                } else {
                    cout << "\n\tAdmin login failed.\n";
                }
                system("pause");
                break;
            case '3':
                system("CLS");
                cout << "\n\n\n\tThank you for using our program!\n\n\n";
                exit(0);
            default:
                cout << "\n\tInvalid Choice! ";
                system("pause");
        }
    } while (ch != '3');

    return 0;
}
