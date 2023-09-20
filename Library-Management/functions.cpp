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

void User::addUser(string username, string password, bool isAdmin) {
    Users users;

    users.username = username;
    users.password = password;
    users.isAdmin = isAdmin;

    usersList.push_back(users);
}

void User::displayAllUsers() {
    if (usersList.empty())
        exit(1);

    else {
        for (auto & i : usersList) {
            cout << i.username << " | " << i.password << " | " << i.isAdmin << endl;
        }
    }
}