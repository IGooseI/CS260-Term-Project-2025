#include "SavingsAccount.h"

	// Constructors
	SavingAccount::SavingAccount() : Account()
	{
		interestRate = 7;
	}
	SavingAccount::SavingAccount(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer _accountCustomer, double _interestRate) : Account(_firstName, _lastName, _address, _phone, _email, _ID, _balance,
		_withdrawalCounter, _depositsCounter, _accountCustomer)
	{
		interestRate = _interestRate;
	}
	// Setters
	void SavingAccount::setAll(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer _accountCustomer, double _interestRate)
	{
		interestRate = _interestRate;
		_accountCustomer.setAll(_firstName, _lastName, _address, _phone, _email);
		Account::setAll(_firstName, _lastName, _address, _phone, _email, _ID, _balance, _withdrawalCounter, _depositsCounter, _accountCustomer);
		setAccountCustomer(_accountCustomer);
	}
	void SavingAccount::setInterestRate(double _interestRate)
	{
		interestRate = _interestRate;
	}
	// Getters
	double SavingAccount::getInterestRate() const
	{
		return interestRate;
	}
	// Functions
	void SavingAccount::payInterestRate()
	{
		balance += (balance * interestRate);
	}
	void SavingAccount::transfer(double& amount, SavingAccount destinationAccount)
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
