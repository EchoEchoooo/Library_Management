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
        string contactNo;
    };
    vector<Users> usersList;

    struct BorrowedBooks {
        string username;
        string ISBN;
        string borrowDate;
        string returnDate;
    };
    vector<BorrowedBooks> borrowedBooksList;

public:
    void serializeUsers();

    void deserializeUsers();

    void addUser(string username, string password, int contactNo);

    void modifyUser(string username);

    void deleteUser(string username);

    void displayAllUsers();

    bool loginUser(string username, string password);
};

class Admin : public User {
private:
    vector<Users> adminsList;
public:
    void serializeUsers();

    void deserializeUsers();

    void addUser(string username, string password, int contactNo);

    void deleteUser(string username);

    bool loginUser(string username, string password);
};

#endif //LIBRARY_MANAGEMENT_USER_H