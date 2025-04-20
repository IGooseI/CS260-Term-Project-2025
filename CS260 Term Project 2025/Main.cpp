#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Customer.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "PasswordSystem.h"
#include "Manager.h"
using namespace std;

// Reminders:
// DONE *Input Validation 
// DONE *Const on Getters
// Done *Use of Constructors
// Do the Main
// IMPORTANT!! Check Blackboard for what Sarraf wants involving pointers and dynamic memory allocation
int main()
{


	const int MAX_NUM = 100;
	const int MAX_NUM_C = 200;
	Customer customerList[MAX_NUM_C];
	CheckingAccount customerChecking[MAX_NUM];
	SavingAccount customerSaving[MAX_NUM];
		
		
	int choice = 0;
	int countCustomer = 0;
	int countChecking = 0;
	int countSaving = 0;
	string _firstName, _lastName, _address, _phone, _email;
	int _ID, _withdrawalCounter, _depositsCounter;
	double _balance, _overDraftLimit, _interestRate;

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
				if (countChecking >= MAX_NUM)
				{
					cout << "Error: Maximum number of customers reached.\n";
					choice = 7;
				}
				else 
				{
					cout << "Enter First Name: "; cin >> _firstName;
					cout << "Enter Last Name: "; cin >> _lastName;
					cout << "Enter Address: "; getline(cin, _address);
					cout << "Enter Phone number: "; getline(cin, _phone);
					cout << "Enter Email: "; getline(cin, _email);
					cout << "Enter ID: "; cin >> _ID;
					cout << "Enter Balance: "; cin >> _balance;
					cout << "Enter Withdraw Counter: "; cin >> _withdrawalCounter;
					cout << "Enter Deposit Counter: "; cin >> _depositsCounter;
					cout << "Enter Over draft Limit: "; cin >> _overDraftLimit;
					customerList[countCustomer].setAll(_firstName, _lastName, _address, _phone, _email);
					customerChecking[countChecking].setAll( _firstName,_lastName,  _address,  _phone,  _email,  _ID,  _balance, _withdrawalCounter,  _depositsCounter,  customerList[countCustomer], _overDraftLimit);
					countChecking++;
				}
				break;
			case 2:
				if (countSaving >= MAX_NUM)
				{
					cout << "Error: Maximum number of customers reached.\n";
					choice = 7;
				}
				else
				{
					cout << "Enter First Name: "; cin >> _firstName;
					cout << "Enter Last Name: "; cin >> _lastName;
					cout << "Enter Address: "; getline(cin, _address);
					cout << "Enter Phone number: "; getline(cin, _phone);
					cout << "Enter Email: "; getline(cin, _email);
					cout << "Enter ID: "; cin >> _ID;
					cout << "Enter Balance: "; cin >> _balance;
					cout << "Enter Withdraw Counter: "; cin >> _withdrawalCounter;
					cout << "Enter Deposit Counter: "; cin >> _depositsCounter;
					cout << "Enter Interest Rate: "; cin >> _interestRate;
					customerList[countCustomer].setAll(_firstName, _lastName, _address, _phone, _email);
					customerSaving[countSaving].setAll( _firstName,  _lastName,  _address,  _phone,  _email,  _ID,  _balance,  _withdrawalCounter,  _depositsCounter,  customerList[countCustomer], _interestRate);
					countSaving++;

				}

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
