#pragma once
#ifndef _Account_
#define _Account_
#include "Customer.h"

class Account : public Customer
{

protected:

	int ID;
	double balance;
	int withdrawalCounter = 0;
	int depositsCounter = 0;
	Customer accountCustomer;
public:
	// Constructors
	Account();
	Account(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, 
		int _withdrawalCounter, int _depositsCounter, Customer _accountCustomer);
	// Setters
	void setID(int _ID);
	void setBalance(double _balance);
	void setWithdrawalCounter(int _withdrawalCounter);
	void setDepositsCounter(int _depositsCounter);
	void setAccountCustomer(Customer _accountCustomer);
	// Getters
	int getID() const;
	double getBalance() const;
	int getWithdrawalCounter() const;
	int getDepositsCounter() const;
	Customer getAccountCustomer() const;
	// Functions
	void setAll(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer _accountCustomer);
	void depositMoney(double amount);
	void withdrawMoney(double amount);
};

#endif // !_Account_