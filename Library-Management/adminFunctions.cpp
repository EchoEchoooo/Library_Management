//
// Created by Chairo on 9/22/2023.
//

#include "headers/User.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void Admin::serializeUsers() { //Write to admins text file
    ofstream adminsFile("admins.txt");

    if(adminsFile.is_open()) {
        for (auto & i : adminsList) {
            adminsFile << i.username << "|" << i.password << "|" << i.contactNo << endl;
        }
    }

    adminsFile.close();
}

void Admin::deserializeUsers() { // Read from admins text file
    ifstream adminsFile("admins.txt");
    string line, username, password;
    int contactNo;

    while (getline(adminsFile, line)) {
        size_t pos = line.find('|');

        if (pos != string::npos) {
            username = line.substr(0, pos);
            line.erase(0, pos + 1); // nireremove neto yung |

            pos = line.find('|');

            if (pos != string::npos) {
                password = line.substr(0, pos);
                line.erase(0, pos + 1); // nireremove neto yung |

                contactNo = stoi(line);

                addUser(username, password, contactNo);
            }
        }
    }

    adminsFile.close();
}

void Admin::addUser(string username, string password, int contactNo) {
    Users admins;

    admins.username = username;
    admins.password = password;
    admins.contactNo = contactNo;

    adminsList.push_back(admins);
}

void Admin::deleteUser(string username) {
    if (usersList.empty())
        cout << "\n\tThere are no users\n";

    else {
        for (auto i = usersList.begin(); i != usersList.end(); ++i) {
            if (i->username == username) {
                usersList.erase(i);
                cout << endl << username << " has been successfully deleted\n";
                break;
            }

            else
                cout << "\n\tUser not found";
        }
    }
}

void Admin::deleteAdmin(string username, string password) {
    if (adminsList.empty())
        exit(1);

    else {
        for (auto i = adminsList.begin(); i != adminsList.end(); ++i) {
            if (i->username == username && i->password == password) {
                adminsList.erase(i);
                cout << endl << username << " has been successfully deleted\n";
                break;
            }

            else
                cout << "\n\tUser not found or incorrect password\n";
        }
    }
}

void Admin::searchUser(string username) {
    if (adminsList.empty())
        cout << "There are no users\n";

    else {
        for (auto & i : adminsList) {
            if (i.username == username) {
                //display all user details
                break;
            }
        }

    }
}

void Admin::displayAllUsers() { //display all the users in the vector
    if (adminsList.empty())
        exit(1);

    else {
        for (auto & i : adminsList) {
            cout << i.username << " | " << i.password << " | " << i.contactNo << endl;
        }
    }
}

void Admin::modifyUser(string username) {
    string password,newUsername, newPassword;

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
            cout << "Enter New Password: ";
            cin >> newPassword;

            for (auto & i : usersList) {
                if (i.username == username)  {
                    i.password = newPassword;

                    cout << "\nPassword changed successfully\n";
                    break;
                }
            }
            break;

        default:
            //wrong input here
            break;
    }
}

void Admin::modifyAdmin(string username) {
    string password,newUsername, newPassword;

    int ch;
    cout << "\n\t1. Change Username: ";
    cout << "\n\t2. Change Password: ";
    cin >> ch;

    switch(ch) {
        case 1:
            cout << "Enter New Username: ";
            cin >> newUsername;

            for (auto & i : adminsList) {
                if (i.username == username) {
                    i.username = newUsername;

                    cout << endl << username << " has been changed to " << newUsername << endl;
                    break;
                }
            }
            break;

        case 2:
            cout << "Enter New Password: ";
            cin >> newPassword;

            for (auto & i : usersList) {
                if (i.username == username)  {
                    i.password = newPassword;

                    cout << "\nPassword changed successfully\n";
                    break;
                }
            }
            break;

        default:
            //wrong input here
            break;
    }
}

bool Admin::loginUser(string username, string password) {
    if (adminsList.empty()) {
        //ask to create admin account?
    }

    else {
        for (auto & i : adminsList) {
            if (i.username == username && i.password == password)
                return true;
        }
    }

    return false;
}