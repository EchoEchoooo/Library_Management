#include "data.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std; // Only added here, not in the header file

void User::serializeUsers() { //Write to users text file
    ofstream usersFile("users.txt");

    if(usersFile.is_open()) {
        for (auto & i : usersList) {
            usersFile << i.username << "|" << i.password << "|" << i.isAdmin << endl;
        }
    }

    usersFile.close();
}

void User::deserializeUsers() { // Read from users text file
    ifstream usersFile("users.txt");
    string line, username, password;
    bool isAdmin;

    while (getline(usersFile, line)) {
        size_t pos = line.find('|');

        if (pos != string::npos) {
            username = line.substr(0, pos);
            line.erase(0, pos + 1); // nireremove neto yung |

            pos = line.find('|');

            if (pos != string::npos) {
                password = line.substr(0, pos);
                line.erase(0, pos + 1); // nireremove neto yung |

                isAdmin = stoi(line);

                addUser(username, password, isAdmin);
            }
        }
    }

    usersFile.close();
}

void User::addUser(string username, string password, bool isAdmin) { //adds a user to the user vector
    Users users;

    users.username = username;
    users.password = password;
    users.isAdmin = isAdmin;

    usersList.push_back(users);
}

void User::deleteUser(string username) {
    if (usersList.empty())
        exit(1);

    else {
        for (auto i = usersList.begin(); i != usersList.end(); ++i) {
            if (i->username == username) {  //login when user is admin
                usersList.erase(i);
                cout << endl << username << " has been deleted\n";
                break;
            }

            else {}//do something
        }
    }
}

void User::searchUser(string username) {
    if (usersList.empty())
        cout << "There are no users\n";

    else {
        for (auto & i : usersList) {
            if (i.username == username) {
                //display all user details
                break;
            }
        }
    }
}

void User::modifyUser(string username) {
    string currentUser, password, newUsername, newPassword;

    int ch;
    cout << "\n\t1. Change Username: ";
    cout << "\n\t2. Change Password: ";
    cin >> ch;

    switch(ch) {
        case 1:
            cout << "Enter New Username: ";
            cin >> newUsername;

            for (auto & i : usersList) {
                if (i.username == username) {
                    i.username = newUsername;

                    cout << endl << username << " has been changed to " << newUsername << endl;
                    break;
                }
            }

            break;

        case 2:
            cout << "Enter Current Password: ";
            cin >> password;
            cout << "Enter New Password: ";
            cin >> newPassword;

            for (auto & i : usersList) {
                if (i.username == username && i.password == password)  {
                    i.password = newPassword;

                    cout << "\nPassword changed successfully\n";
                    break;
                }

                else
                    cout << endl << "Incorrect password, please try again\n";
            }

            break;

        default:
            break;
    }
}

void User::displayAllUsers() { //display all the users in the vector
    if (usersList.empty())
        exit(1);

    else {
        for (auto & i : usersList) {
            cout << i.username << " | " << i.password << " | " << i.isAdmin << endl;
        }
    }
}

bool User::userLogin(string username, string password) {
    if (usersList.empty())
        exit(1);

    else {
        for (auto & i : usersList) {
            if (i.username == username && i.password == password) { //login when user is admin
                return true;
            }

            else
                return false;
        }
    }
}


bool User::adminLogin(string username, string password) {
    if (usersList.empty())
        exit(1);

    else {
        for (auto & i : usersList) {
            if (i.username == username && i.password == password && i.isAdmin) { //login when user is admin
                return true;
            }

            else
                return false;
        }
    }
}