//
// Created by Chairo on 9/22/2023.
//

#ifndef LIBRARY_MANAGEMENT_USER_H
#define LIBRARY_MANAGEMENT_USER_H

#include <vector>
#include <string>
using namespace std;

class User {
protected:
    struct Users {
        //string firstName, middleName, lastName;
        string username;
        string password;
        int contactNo;
    };
    vector<Users> usersList;

    struct BorrowedBooks {
        string username;
        vector<int> ISBNs;
    };
    vector<BorrowedBooks> borrowedBooksList;

public:
    void serializeUsers();
    void deserializeUsers();

    void addUser(string username, string password, int contactNo);
    void modifyUser(string username);

    //void displayAnalytics();

    bool loginUser(string username, string password);
    //bool userExists(string username);
};

class Admin: public User {
private:
    vector<Users> adminsList;
public:
    void serializeUsers();
    void deserializeUsers();

    void addUser(string username, string password, int contactNo);

    void deleteUser(string username);
    void deleteAdmin(string username, string password);

    void modifyUser(string username);
    void modifyAdmin(string username);

    void searchUser(string username);

    void displayAllUsers();
    bool loginUser(string username, string password);
};

#endif //LIBRARY_MANAGEMENT_USER_H