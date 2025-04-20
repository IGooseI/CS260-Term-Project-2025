#pragma once
#ifndef _PasswordSystem_
#define _PasswordSystem_
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class PasswordSystem
{
	string password;
protected:
	void setPassword(string _password);
public:
	PasswordSystem();
	PasswordSystem(string _password);
	string getPassword() const;
	bool checkPassword(string _password) const;
};

#endif // !_PasswordSystem_