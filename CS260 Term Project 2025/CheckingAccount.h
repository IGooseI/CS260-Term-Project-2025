#pragma once
#ifndef _CheckingAccount_
#define _CheckingAccount_
#include "Account.h"

class CheckingAccount : public Account
{
	double overDraftLimit;
public:
	// Constructors
	CheckingAccount(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance,
		int _withdrawalCounter, int _depositsCounter, Customer _accountCustomer) : Account(_firstName, _lastName, _address, _phone, _email, _ID, _balance,
			_withdrawalCounter, _depositsCounter, _accountCustomer);
	CheckingAccount(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer _accountCustomer, double _overDraftLimit) : Account(_firstName, _lastName, _address, _phone, _email, _ID, _balance, _withdrawalCounter, _depositsCounter, _accountCustomer);
	// Setters
	void setOverDraftLimit(double _overDraftLimit);
	void setAll(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance,
		int _withdrawalCounter, int _depositsCounter, Customer _accountCustomer, double _overDraftLimit);
	// Getters
	double getOverDraftLimit() const;
	// Functions
	void withdrawMoney(double amount);

};
#endif // !_CheckingAccount_
