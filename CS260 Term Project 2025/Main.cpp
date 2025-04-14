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