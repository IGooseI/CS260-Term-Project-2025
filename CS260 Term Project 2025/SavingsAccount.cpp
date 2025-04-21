#include "SavingsAccount.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Constructors
SavingAccount::SavingAccount() : Account()
{
    interestRate = 0.05; // default 5% interest
}

SavingAccount::SavingAccount(int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer* _accountCustomer, double _interestRate)
    : Account(_ID, _balance, _withdrawalCounter, _depositsCounter, _accountCustomer)
{
    setInterestRate(_interestRate);
}

// Setters
void SavingAccount::setInterestRate(double _interestRate)
{
    if (_interestRate >= 0)
        interestRate = _interestRate;
    else
    {
        cout << "Invalid interest rate. Setting to 0.\n";
        interestRate = 0;
    }
}

void SavingAccount::setAll(int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer* _accountCustomer, double _interestRate)
{
    Account::setAll(_ID, _balance, _withdrawalCounter, _depositsCounter, _accountCustomer);
    setInterestRate(_interestRate);
}

// Getters
double SavingAccount::getInterestRate() const
{
    return interestRate;
}

// Apply interest
void SavingAccount::payInterestRate()
{
    double earnedInterest = balance * interestRate;
    balance += earnedInterest;
    cout << "Interest of $" << fixed << setprecision(2) << earnedInterest << " applied to Account ID " << ID << ".\n";
}

// Transfer funds to another saving account
void SavingAccount::transfer(double amount, SavingAccount& destinationAccount)
{
    if (amount <= 0)
    {
        cout << "Invalid transfer amount.\n";
        return;
    }

    if (balance >= amount)
    {
        balance -= amount;
        destinationAccount.balance += amount;
        cout << "Transferred $" << fixed << setprecision(2) << amount
            << " from Account ID " << ID
            << " to Account ID " << destinationAccount.getID() << ".\n";
    }
    else
    {
        cout << "Insufficient funds to transfer $" << amount << " from Account ID " << ID << ".\n";
    }
}

// PrintInfo override
void SavingAccount::PrintInfo() const
{
    Account::PrintInfo();
    cout << "Interest Rate      : " << fixed << setprecision(2) << (interestRate * 100) << "%\n";
}
