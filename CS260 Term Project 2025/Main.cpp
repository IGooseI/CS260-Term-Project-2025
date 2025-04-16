#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Customer.h"
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
using namespace std;

// Reminders:
// *Input Validation
// *Const on Getters
// *Use of Constructors
// Maybe make a randomly generated password for the password system class using cstdlib and rand functions
// Transaction History File system using fstream library
// Do the Main
// IMPORTANT!! Check Blackboard for what Sarraf wants involving pointers and dynamic memory allocation
class PasswordSystem
{
	string password;
protected:
	void setPassword(string _password)
	{
		password = _password;
	}
public:
	PasswordSystem()
	{
		password = "";
	}
	PasswordSystem(string _password)
	{
		password = _password;
	}
	string getPassword() const
	{
		return password;
	}
	bool checkPassword(string _password) const
	{
		if (_password == password)
			return true;
		else
			return false;
	}
};
class Manager : public Account, protected PasswordSystem
{
	string username, userPassword;
protected:
	void setUsername(string _username)
	{
		username = _username;
	}
	void setUserPassword(string _userPassword)
	{
		userPassword = _userPassword;
	}

public:
	Manager()
	{
		username = "";
		userPassword = "";
	}
	Manager(string _username, string _userPassword)
	{
		username = _username;
		userPassword = _userPassword;
	}
	string getUsername() const
	{
		return username;
	}
	string getUserPassword() const
	{
		return userPassword;
	}
	bool checkUserPassword(string _userPassword) const
	{
		if (_userPassword == userPassword)
			return true;
		else
			return false;
	}
	void setAll(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance,
		int _withdrawalCounter, int _depositsCounter, Customer _accountCustomer, string _username, string _userPassword)
	{
		Account::setAll(_firstName, _lastName, _address, _phone, _email, _ID, _balance, _withdrawalCounter, _depositsCounter, _accountCustomer);
		setUsername(_username);
		setUserPassword(_userPassword);
	}


};
int main()
{
	//Customer customer1{1, "Iver" , "Gustafson", "2800 University Blvd", "484-374-8955", "igustaf@jacksonville.edu"};
	//customer1.PrintInfo();

	int MAX_NUM = 10;
	Customer customerList[10];
	CheckingAccount customerChecking[10];
	SavingAccount customerSaving[10];
		
		
	int choice = 0;
		
	do		
	{
				
		cout << "\n" << setw(30) << setfill('=') << "=" << endl;
		cout << "\n" << setfill(' ') << setw(20) << left << "Banking System Menu" << endl;
		cout << setw(30) << setfill('-') << "-" << endl;
		cout << "1. Create Checking Account" << endl;
		cout << "2. Create Saving Account" << endl;
		cout << "3. Modify Account" << endl;
		cout << "4. View Account" << endl;
		cout << "5. Transfer Funds" << endl;
		cout << "6. Exit Program" << endl;
		cout << setw(30) << setfill('=') << "=" << "\n";
		cout << "Enter your choice: ";
			cin >> choice;
		switch (choice)
		{
			case 1:


				break;
			case 2:


				break;
			case 3:


				break;
			case 4:


				break;
			case 5:


				break;
			case 6:


				break;
			case 7:
			cout << "Invalid Choice Selection." << endl;


				break;
		default:
			system("cls");
			break;
		}
	} while (choice != 7);
	
	system("pause");
	return 0;
}
