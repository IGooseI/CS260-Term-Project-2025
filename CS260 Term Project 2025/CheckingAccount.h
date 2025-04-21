#pragma once
#ifndef _CheckingAccount_
#define _CheckingAccount_

#include "Account.h"

class CheckingAccount : public Account
{
private:
    double overDraftLimit;

public:
    // Constructors
    CheckingAccount();
    CheckingAccount(int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer* _accountCustomer, double _overDraftLimit);

    // Setters
    void setOverDraftLimit(double _overDraftLimit);
    void setAll(int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer* _accountCustomer, double _overDraftLimit);

    // Getters
    double getOverDraftLimit() const;

    // Functions
    void withdrawMoney(double amount) override;
    void PrintInfo() const override;
};

#endif // !_CheckingAccount_
