#include "Manager.h"

// Constructors
Manager::Manager()
{
    username = "";
    password = "";
}

Manager::Manager(string _username, string _password)
{
    username = _username;
    password = _password;
}

// Setters
void Manager::setUsername(string _username)
{
    username = _username;
}

void Manager::setUserPassword(string _password)
{
    setPassword(_password);
}

// Getters
string Manager::getUsername() const
{
    return username;
}

string Manager::getUserPassword() const
{
    return password;
}

// Validator
bool Manager::checkUserPassword(string _password) const
{
    return checkPassword(_password);
}

// Set all
void Manager::setAll(string _username, string _password)
{
    setUsername(_username);
    setPassword(_password);
}
