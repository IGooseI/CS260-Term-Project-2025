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
// *Use of Constructors
// Transaction History File system using fstream library
// Do the Main
// IMPORTANT!! Check Blackboard for what Sarraf wants involving pointers and dynamic memory allocation
int main()
{


	const int MAX_NUM = 100;
	Customer customerList[MAX_NUM];
	CheckingAccount customerChecking[MAX_NUM];
	SavingAccount customerSaving[MAX_NUM];
		
		
	int choice = 0;
	int countChecking = 0;
	int countSaving = 0;

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
