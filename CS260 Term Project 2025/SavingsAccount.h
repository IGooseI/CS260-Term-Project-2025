#pragma once
#ifndef _SavingAccount_
#define _SavingAccount_
#include "Account.h"

class SavingAccount : public Account
{
	double interestRate;
public:
	// Constructors
	SavingAccount();
	SavingAccount(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer _accountCustomer, double _interestRate);
	// Setters
	void setAll(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer _accountCustomer, double _interestRate);
	void setInterestRate(double _interestRate);
	// Getters
	double getInterestRate() const;
	// Functions
	void payInterestRate();
	void transfer(double& amount, SavingAccount destinationAccount);
};

#endif // !_SavingAccount_
