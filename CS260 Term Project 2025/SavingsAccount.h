#pragma once
#ifndef _SavingAccount_
#define _SavingAccount_

#include "Account.h"

class SavingAccount : public Account
{
private:
    double interestRate;

public:
    // Constructors
    SavingAccount();
    SavingAccount(int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer* _accountCustomer, double _interestRate);

    // Setters
    void setInterestRate(double _interestRate);
    void setAll(int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer* _accountCustomer, double _interestRate);

    // Getters
    double getInterestRate() const;

    // Functions
    void payInterestRate(); // applies interest to balance
    void transfer(double amount, SavingAccount& destinationAccount); // fund transfer
    void PrintInfo() const override;
};

#endif // !_SavingAccount_
