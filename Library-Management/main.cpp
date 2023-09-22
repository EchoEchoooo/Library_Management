#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "headers/User.h"
#include "headers/Book.h"

using namespace std;

int main()
{
    User user;
    Admin admin;

    user.deserializeUsers();
    admin.deserializeUsers();
    string username, password;
    int contactNo;

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
            {
                /*int studentChoice;
                do {
                    system("CLS");
                    cout << "\n\n";
                    cout << setw(50) << " Student Menu";
                    cout << "\n\n\t1. Login";
                    cout << "\n\n\t2. Register";
                    cout << "\n\n\t3. Back to main menu";
                    cout << "\n\n\tChoose an option: ";
                    cin >> studentChoice;
                    switch (studentChoice) {
                        case 1:
                            if (studentLogin()) {
                                cout << "\n\tStudent login successful.\n";

                            } else {
                                cout << "\n\tStudent login failed.\n";
                            }
                            system("pause");
                            break;
                        case 2:
                            registerAccount();
                            system("pause");
                            break;
                        case 3:
                            break;
                        default:
                            cout << "\n\tInvalid Choice! ";
                            system("pause");
                    }
                } while (studentChoice != 3);*/
            }
                break;
            case '2':
                cout << "Enter Username: ";
                cin >> username;
                cout << "Enter Password: ";
                cin >> password;

                if (admin.loginUser(username, password)) {
                    cout << "\n\tAdmin login successful.\n";
                    int adminChoice;
                    do {
                        //2system("CLS");
                        cout << "\n\n";
                        cout << setw(50) << " Admin Menu";
                        cout << "\n\n\t1. Add books";
                        cout << "\n\n\t2. Modify books";
                        cout << "\n\n\t3. Delete books";
                        cout << "\n\n\t4. Display all books";
                        cout << "\n\n\t5. Create student account";
                        cout << "\n\n\t6. Modify student account";
                        cout << "\n\n\t7. Delete student account";
                        cout << "\n\n\t8. Display student accounts";
                        cout << "\n\n\t9. Back to main menu";
                        cout << "\n\n\tChoose an option: ";
                        cin >> adminChoice;
                        switch (adminChoice) {
                            case 1: //addBook();
                                break;
                            case 2: //modifyBook();
                                break;
                            case 3: //deleteBook();
                                break;
                            case 4: //displayBooks();
                                break;
                            case 5:
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
                            case 6:
                                cout << "Enter account username to modifyL: ";
                                cin >> username;

                                user.modifyUser(username);
                                break;
                            case 7:
                                cout << "Enter Username: ";
                                cin >> username;
                                admin.deleteUser(username);
                                break;
                            case 8:
                                user.displayAllUsers();
                                break;
                            case 9:
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
                break;
            default:
                cout << "\n\tInvalid Choice! ";
                system("pause");
        }

    } while (ch != '3');

    return 0;
}
