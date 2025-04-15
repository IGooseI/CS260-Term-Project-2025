#include <iostream>
#include <string>
#include <iomanip>
#include "Customer.h"
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
using namespace std;

// Reminders:
// *Input Validation
// *Const on Getters


class SavingAccount : public Account
{
	double interestRate;
public:
	// Constructors
	SavingAccount() : Account()
	{
		interestRate = 7;
	}
	SavingAccount(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer _accountCustomer, double _interestRate) : Account(_firstName, _lastName, _address, _phone, _email, _ID, _balance,
		_withdrawalCounter, _depositsCounter, _accountCustomer)
	{
		interestRate = _interestRate;
	}
	// Setters
	void setAll(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer _accountCustomer, double _interestRate)
	{
		interestRate = _interestRate;
		_accountCustomer.setAll(_firstName, _lastName, _address, _phone, _email);
		Account::setAll(_firstName, _lastName, _address, _phone, _email, _ID, _balance, _withdrawalCounter, _depositsCounter, _accountCustomer);
		setAccountCustomer(_accountCustomer);
	}
	void setInterestRate(double _interestRate)
	{
		interestRate = _interestRate;
	}
	// Getters
	double getInterestRate() const
	{
		return interestRate;
	}
	// Functions
	void payInterestRate()
	{
		balance += (balance * interestRate);
	}
	void transfer(double & amount, SavingAccount destinationAccount)
	{
		if (balance > amount)
		{
			destinationAccount.balance += amount;
			balance -= amount;
			cout << "You've Successfully Transferred $" << amount << " to ID: " << destinationAccount.getID() << " from ID: " << getID() << endl;
		}
		else if (balance < amount)
		{
			cout << "You do not have enough Money in your account to transfer. Please Try Another Account or Deposit." << endl;
			return;
		}
		else
		{
			cout << "Invalid Entry...Retry" << endl;
			return;
		}
	}
};
int main()
{
	//Customer customer1{1, "Iver" , "Gustafson", "2800 University Blvd", "484-374-8955", "igustaf@jacksonville.edu"};
	//customer1.PrintInfo();
	int choice;
	do
	{
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


				break;
		default:
			cout << "Invalid Choice Selection." << endl;
			break;
		}


		
	

	} while (choice != 7);
	

	return 0;
}
