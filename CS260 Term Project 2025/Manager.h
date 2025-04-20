#pragma once
#ifndef _Manager_
#define _Manager_
#include "Account.h"
#include "PasswordSystem.h"

class Manager : public Account, protected PasswordSystem
{
	string username, userPassword;
protected:
	void setUsername(string _username);
	void setUserPassword(string _userPassword);

public:
	Manager();
	Manager(string _username, string _userPassword);
	string getUsername() const;
	string getUserPassword() const;
	bool checkUserPassword(string _userPassword) const;
	void setAll(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance,
		int _withdrawalCounter, int _depositsCounter, Customer _accountCustomer, string _username, string _userPassword);

};

#endif // !_Manager_
