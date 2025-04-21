#include "Account.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Constructors
Account::Account()
{
    ID = -1;
    balance = 0.0;
    withdrawalCounter = 0;
    depositsCounter = 0;
    accountCustomer = nullptr;
}

Account::Account(int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer* _accountCustomer)
{
    setAll(_ID, _balance, _withdrawalCounter, _depositsCounter, _accountCustomer);
}

// Setters
void Account::setID(int _ID)
{
    if (_ID >= 0 && _ID <= 999)
        ID = _ID;
    else
    {
        cout << "Invalid ID. Setting ID to -1.\n";
        ID = -1;
    }
}

void Account::setBalance(double _balance)
{
    if (_balance >= 0)
        balance = _balance;
    else
    {
        cout << "Invalid balance. Setting balance to 0.\n";
        balance = 0;
    }
}

void Account::setWithdrawalCounter(int _withdrawalCounter)
{
    withdrawalCounter = _withdrawalCounter;
}

void Account::setDepositsCounter(int _depositsCounter)
{
    depositsCounter = _depositsCounter;
}

void Account::setAccountCustomer(Customer* _accountCustomer)
{
    accountCustomer = _accountCustomer;
}

// Getters
int Account::getID() const 
{ 
    return ID; 
}
double Account::getBalance() const 
{
    return balance; 
}
int Account::getWithdrawalCounter() const 
{ 
    return withdrawalCounter; 
}
int Account::getDepositsCounter() const 
{ 
    return depositsCounter; 
}
Customer* Account::getAccountCustomer() const
{ 
    return accountCustomer; 
}

// setAll function
void Account::setAll(int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer* _accountCustomer)
{
    setID(_ID);
    setBalance(_balance);
    setWithdrawalCounter(_withdrawalCounter);
    setDepositsCounter(_depositsCounter);
    setAccountCustomer(_accountCustomer);
}

// depositMoney
void Account::depositMoney(double amount)
{
    if (amount <= 0)
    {
        cout << "Invalid deposit amount. Must be greater than 0.\n";
        return;
    }

    balance += amount;
    depositsCounter++;
    cout << "Successfully deposited $" << fixed << setprecision(2) << amount << " to Account ID " << ID << ".\n";
}

// withdrawMoney
void Account::withdrawMoney(double amount)
{
    if (amount <= 0)
    {
        cout << "Invalid withdrawal amount.\n";
        return;
    }

    if (balance >= amount)
    {
        balance -= amount;
        withdrawalCounter++;
        cout << "Successfully withdrew $" << fixed << setprecision(2) << amount << " from Account ID " << ID << ".\n";
    }
    else
    {
        cout << "Insufficient funds to withdraw $" << amount << " from Account ID " << ID << ".\n";
    }
}

// PrintInfo
void Account::PrintInfo() const
{
    cout << "\n======== Account Info ========\n";
    cout << "Account ID       : " << ID << "\n";
    cout << "Balance          : $" << fixed << setprecision(2) << balance << "\n";
    cout << "Withdrawals Made : " << withdrawalCounter << "\n";
    cout << "Deposits Made    : " << depositsCounter << "\n";
    cout << "------------------------------\n";
    if (accountCustomer)
    {
        cout << "Customer Information:\n";
        accountCustomer->PrintInfo();
    }
    else
    {
        cout << "No customer assigned to this account.\n";
    }
    cout << "==============================\n";
}
