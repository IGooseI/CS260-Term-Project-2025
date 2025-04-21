#pragma once
#ifndef _PasswordSystem_
#define _PasswordSystem_

#include <string>
using namespace std;

class PasswordSystem
{
protected:
    string password;

public:
    // Constructors
    PasswordSystem();
    PasswordSystem(string _password);

    // Setter
    void setPassword(string _password);

    // Getter
    string getPassword() const;

    // Validation
    bool checkPassword(const string& _password) const;
};

#endif // !_PasswordSystem_
