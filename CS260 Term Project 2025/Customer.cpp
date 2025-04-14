#include "Customer.h"

Customer::Customer()
{
	firstName = "";
	lastName = "";
	address = "";
	phone = "";
	email = "";
}
Customer::Customer(string _firstName, string _lastName, string _address, string _phone, string _email)
{
	firstName = _firstName;
	lastName = _lastName;
	address = _address;
	phone = _phone;
	email = _email;
}
// Setters
void Customer::setAll(string _firstName, string _lastName, string _address, string _phone, string _email)
{
	firstName = _firstName;
	lastName = _lastName;
	address = _address;
	phone = _phone;
	email = _email;
}

void Customer::setFirstName(string _firstName)
{
	firstName = _firstName;
}
void Customer::setLastName(string _lastName)
{
	lastName = _lastName;
}
void Customer::setAddress(string _address)
{
	address = _address;
}
void Customer::setPhone(string _phone)
{
	phone = _phone;
}
void Customer::setEmail(string _email)
{
	email = _email;
}
// Getters

string Customer::getFirstName() const
{
	return firstName;
}
string Customer::getLastName() const
{
	return lastName;
}
string Customer::getAddress() const
{
	return address;
}
string Customer::getPhone() const
{
	return phone;
}
string Customer::getEmail() const
{
	return email;
}
// Functions
void Customer::PrintInfo() const
{
	cout << string(40, '=') << '\n';
	//cout << setw(25) << left << "Customer ID:" << ID << '\n';
	cout << setw(25) << left << "Name:" << firstName << " " << lastName << '\n';
	cout << setw(25) << left << "Email:" << email << '\n';
	cout << setw(25) << left << "Phone:" << phone << '\n';
	cout << setw(25) << left << "Address:" << address << '\n';
	cout << string(40, '=') << '\n';
}