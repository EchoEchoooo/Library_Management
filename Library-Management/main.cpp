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
        cout << "\n\n";
        cout << "\t===================================================================" << endl;
        cout << "\t\t  L I B R A R Y  M A N A G E M E N T  S Y S T E M" << endl;
        cout << "\t===================================================================" << endl;
        cout << "\n\t1. Student";
        cout << "\n\n\t2. Admin";
        cout << "\n\n\t3. Exit";
        cout << "\n\n\tChoose an Option: ";
        cin >> ch;
        cin.ignore();
        switch (ch) {
            case '1':
                cout << "\t===================================================================" << endl;
                cout << "\t\t\t     S T U D E N T   L O G I N" << endl;
                cout << "\t===================================================================" << endl;
                cout << "\n\tEnter Username: ";
                cin >> username;
                cin.ignore();
                cout << "\tEnter Password: ";
                cin >> password;
                cin.ignore();

                if (user.loginUser(username, password)) {
                    cout << "\n\tStudent login successful.\n\n";
                    int userChoice;

                    do {
                        cout << "\t===================================================================" << endl;
                        cout << "\t\t\t      S T U D E N T  M E N U" << endl;
                        cout << "\t===================================================================" << endl;
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
                                cout << "\t===================================================================" << endl;
                                cout << "\t\t\t      B O R R O W   B O O K S" << endl;
                                cout << "\t===================================================================" << endl;
                                cout << "\tEnter Title of the book: ";
                                cin.ignore();
                                getline(cin, userInput);
                                if (book.searchBook(userInput, username)) {
                                    // book found
                                } else {
                                    cout << "\tThe Book you searched is not available.\n\n";
                                }
                                break;
                            case 2:
                                book.showBorrowedBooks(username);
                                break;
                            case 3:
                                cout << "\t===================================================================" << endl;
                                cout << "\t\t\t     R E T U R N I N G   B O O K" << endl;
                                cout << "\t===================================================================" << endl;
                                cout << "\tEnter ISBN of the book: ";
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
                                cout << "Invalid Input. Please try again.\n";
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
                        cout << "\t===================================================================" << endl;
                        cout << setw(50) << "\tA D M I N   M E N U" << endl;
                        cout << "\t===================================================================" << endl;
                        cout << "\n\t[1] Add books";
                        cout << "\n\t[2] Modify books";
                        cout << "\n\t[3] Delete books";
                        cout << "\n\t[4] Display all books";
                        cout << "\n\t[5] Create student account";
                        cout << "\n\t[6] Modify student account";
                        cout << "\n\t[7] Delete student account";
                        cout << "\n\t[8] Display student accounts";
                        cout << "\n\t[9] Back to main menu";
                        cout << "\n\n\tChoose an option: ";
                        cin >> adminChoice;
                        cin.ignore();

                        switch (adminChoice) {
                            case 1: //addBook();
                                cout << "\t===================================================================" << endl;
                                cout << "\t\t\t   A D D I N G   N E W   B O O K" << endl;
                                cout << "\t===================================================================" << endl;
                                cout << "\tEnter Title: ";
                                getline(cin, title);

                                cout << "\tEnter Author: ";
                                getline(cin, author);

                                cout << "\tEnter ISBN: ";
                                getline(cin, isbn);

                                cout << "\tEnter Copies: ";
                                cin >> copies;

                                book.addBook(title, author, isbn, copies);
                                book.serializeBooks();
                                break;
                            case 2: // modifyBook
                                cout << "\t===================================================================" << endl;
                                cout << "\t\t\t     M O D Y F I N G   B O O K" << endl;
                                cout << "\t===================================================================" << endl;
                                cout << "\tEnter ISBN of the book to modify: ";
                                cin >> isbn;
                                book.modifyBook(isbn);
                                book.serializeBooks();
                                break;
                            case 3: //deleteBook
                                cout << "\t===================================================================" << endl;
                                cout << "\t\t\t   D E L E T I N G   B O O K" << endl;
                                cout << "\t===================================================================" << endl;
                                cout << "\tEnter ISBN: ";
                                cin >> isbn;
                                book.deleteBook(isbn);
                                book.serializeBooks();
                                break;
                            case 4: //displayAllBooks
                                book.displayAllBooks();
                                break;
                            case 5: //createStudentAccount
                                cout << "\t===================================================================" << endl;
                                cout << "\t\t     C R E A T E   S T U D E N T   A C C O U N T" << endl;
                                cout << "\t===================================================================" << endl;
                                cout << "\tEnter Username: ";
                                cin >> username;
                                cout << "\tEnter Password: ";
                                cin >> password;
                                cout << "\tEnter Contact No: ";
                                cin >> contactNo;
                                user.addUser(username, password, contactNo);
                                user.serializeUsers();
                                system("pause");
                                break;
                            case 6: //modifyStudentAccount
                                cout << "\t===================================================================" << endl;
                                cout << "\t\tM O D I F Y   S T U D E N T   A C C O U N T" << endl;
                                cout << "\t===================================================================" << endl;
                                cout << "\tEnter account username to modify: ";
                                cin >> username;
                                user.modifyUser(username);
                                user.serializeUsers();
                                break;
                            case 7: //deleteStudentAccount
                                cout << "\t===================================================================" << endl;
                                cout << "\t\t    D E L E T E   S T U D E N T   A C C O U N T" << endl;
                                cout << "\t===================================================================" << endl;
                                cout << "\tEnter Username: ";
                                cin >> username;
                                user.deleteUser(username);
                                user.serializeUsers();
                                break;
                            case 8: //displayStudentAccounts
                                cout << "\t===================================================================" << endl;
                                cout << "\t\t  D I S P L A Y   S T U D E N T   A C C O U N T" << endl;
                                cout << "\t===================================================================" << endl;
                                user.displayAllUsers();
                                break;
                            case 9:
                                cout << "\n\tBack to main menu.\n";
                                break;
                            default:
                                cout << "\n\tInvalid Choice. Please try again.\n ";
                                system("pause");
                        }
                    } while (adminChoice != 9);
                } else {
                    cout << "\n\tAdmin login failed.\n";
                }
                system("pause");
                break;
            case '3':
                cout << "\n\n\n\tThank you for using our program!\n\n\n";
                exit(0);
            default:
                cout << "\n\tInvalid Choice! ";
                system("pause");
        }
    } while (ch != '3');

    return 0;
}
