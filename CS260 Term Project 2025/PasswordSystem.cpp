#include "PasswordSystem.h"

// Constructors
PasswordSystem::PasswordSystem()
{
    password = "";
}

PasswordSystem::PasswordSystem(string _password)
{
    password = _password;
}

// Setter
void PasswordSystem::setPassword(string _password)
{
    password = _password;
}

// Getter
string PasswordSystem::getPassword() const
{
    return password;
}

// Validator
bool PasswordSystem::checkPassword(const string& _password) const
{
    return _password == password;
}
