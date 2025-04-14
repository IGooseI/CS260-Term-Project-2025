#include <iostream>
#include <string>
#include <iomanip>
#include "Customer.h"
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "BankingSystem.h"
using namespace std;

// Reminders:
// *Input Validation
// *Const on Getters

class CheckingAccount : public Account
{
	double overDraftLimit;
public:
	// Constructors
	CheckingAccount(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance,
		int _withdrawalCounter, int _depositsCounter, Customer _accountCustomer) : Account(_firstName, _lastName, _address, _phone, _email, _ID, _balance, 
			_withdrawalCounter, _depositsCounter, _accountCustomer)
	{
		overDraftLimit = 200;
	}
	CheckingAccount(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance,
		int _withdrawalCounter, int _depositsCounter, Customer _accountCustomer, double _overDraftLimit) : Account(_firstName, _lastName, _address, _phone, _email, _ID, _balance,
			_withdrawalCounter, _depositsCounter, _accountCustomer)
	{
		overDraftLimit = _overDraftLimit; // Input Validation
	}
	// Setters
	void setOverDraftLimit(double _overDraftLimit)
	{
		overDraftLimit = _overDraftLimit; // Input Validation
	}
	void setAll(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance,
		int _withdrawalCounter, int _depositsCounter, Customer _accountCustomer, double _overDraftLimit)
	{
		setOverDraftLimit(_overDraftLimit);
		_accountCustomer.setAll(_firstName, _lastName, _address, _phone, _email);
		setAccountCustomer(_accountCustomer);
	}
	// Getters
	double getOverDraftLimit() const
	{
		return overDraftLimit;
	}
	// Functions
	void withdrawMoney(double amount)
	{
		if (balance < amount)
		{
			cout << "There is not enough Funds to withdraw $" << amount << " from Account ID: " << ID << endl;
		}
		else if (balance == amount)
		{
			char opt;
			cout << "The Amount you are trying to Withdraw is equal to the amount in the Account. Would you Still like to Withdraw (Enter y or n)" << endl;
			if (opt == 'y' || opt == 'Y')
			{
				balance -= amount;
				withdrawalCounter++;
				cout << "You've successfully Withdrawn $" << amount << "from Account ID: " << ID << endl;
				cout << "Your balance is now: $" << balance << endl;
			}
			else if (opt == 'n' || opt == 'N')
			{
				cout << "Okay... Your Balance is: $" << balance << endl;
				return;
			}
			else
			{
				cout << "Invalid Entry..." << endl;
				return;
			}
		}
		else if (balance >= amount)
		{
			balance -= amount;
			withdrawalCounter++;
			cout << "You've successfully Withdrawn $" << amount << "from Account ID: " << ID << endl;
			cout << "Your balance is now: $" << balance << endl;
		}
	}

};
class SavingAccount : public Account
{
public:
	// Constructors

	// Setters

	// Getters
};
int main()
{
	//Customer customer1{1, "Iver" , "Gustafson", "2800 University Blvd", "484-374-8955", "igustaf@jacksonville.edu"};
	//customer1.PrintInfo();

	return 0;
}