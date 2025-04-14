#pragma once
#ifndef _Customer_
#define _Customer_
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Customer
{
	string firstName, lastName, address, phone, email;

	//int ID;
public:
	// Constructors
	Customer();
	Customer(string _firstName, string _lastName, string _address, string _phone, string _email);
	// Setters
	void setAll(string _firstName, string _lastName, string _address, string _phone, string _email);
	void setFirstName(string _firstName);
	void setLastName(string _lastName);
	void setAddress(string _address);
	void setPhone(string _phone);
	void setEmail(string _email);
	string getFirstName() const;
	string getLastName() const;
	string getAddress() const;
	string getPhone() const;
	string getEmail() const;
	// Functions
	void PrintInfo() const;
};

#endif // !_Customer_
