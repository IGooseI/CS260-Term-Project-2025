#pragma once
#ifndef _Account_
#define _Account_

#include "Customer.h"

class Account
{
protected:
    int ID;
    double balance;
    int withdrawalCounter;
    int depositsCounter;
    Customer* accountCustomer; // pointer to associated Customer (collaboration)

public:
    // Constructors
    Account();
    Account(int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer* _accountCustomer);

    // Setters
    void setID(int _ID);
    void setBalance(double _balance);
    void setWithdrawalCounter(int _withdrawalCounter);
    void setDepositsCounter(int _depositsCounter);
    void setAccountCustomer(Customer* _accountCustomer);

    // Getters
    int getID() const;
    double getBalance() const;
    int getWithdrawalCounter() const;
    int getDepositsCounter() const;
    Customer* getAccountCustomer() const;

    // Functions
    void setAll(int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer* _accountCustomer);
    void depositMoney(double amount);
    virtual void withdrawMoney(double amount); // virtual to allow overrides
    virtual void PrintInfo() const;
};

#endif // !_Account_
