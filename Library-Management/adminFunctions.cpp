#include "headers/User.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void Admin::serializeUsers() { //Write to admins text file
    ofstream adminsFile("admins.txt");

    if (adminsFile.is_open()) {
        for (auto &i: adminsList) {
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
            line.erase(0, pos + 1); // Remove "|"

            pos = line.find('|');

            if (pos != string::npos) {
                password = line.substr(0, pos);
                line.erase(0, pos + 1); // Remove "|"

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
            } else
                cout << "\n\tUser not found";
        }
    }
}


bool Admin::loginUser(string username, string password) {
    if (adminsList.empty()) {
        //ask to create admin account?
    } else {
        for (auto &i: adminsList) {
            if (i.username == username && i.password == password)
                return true;
        }
    }

    return false;
}