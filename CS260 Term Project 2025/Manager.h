#pragma once
#ifndef _Manager_
#define _Manager_

#include "Account.h"
#include "PasswordSystem.h"
#include <string>
using namespace std;

class Manager : public PasswordSystem
{
private:
    string username;

public:
    // Constructors
    Manager();
    Manager(string _username, string _password);

    // Setters
    void setUsername(string _username);
    void setUserPassword(string _password); // alias to setPassword

    // Getters
    string getUsername() const;
    string getUserPassword() const;

    // Functions
    bool checkUserPassword(string _password) const;
    void setAll(string _username, string _password);
};

#endif // !_Manager_
