#include "CheckingAccount.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Constructors
CheckingAccount::CheckingAccount() : Account()
{
    overDraftLimit = 200.0;
}

CheckingAccount::CheckingAccount(int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer* _accountCustomer, double _overDraftLimit)
    : Account(_ID, _balance, _withdrawalCounter, _depositsCounter, _accountCustomer)
{
    setOverDraftLimit(_overDraftLimit);
}

// Setters
void CheckingAccount::setOverDraftLimit(double _overDraftLimit)
{
    if (_overDraftLimit >= 0)
        overDraftLimit = _overDraftLimit;
    else
    {
        cout << "Invalid overdraft limit. Setting to $0.\n";
        overDraftLimit = 0;
    }
}

void CheckingAccount::setAll(int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer* _accountCustomer, double _overDraftLimit)
{
    Account::setAll(_ID, _balance, _withdrawalCounter, _depositsCounter, _accountCustomer);
    setOverDraftLimit(_overDraftLimit);
}

// Getters
double CheckingAccount::getOverDraftLimit() const
{
    return overDraftLimit;
}

// Overridden withdraw function with overdraft protection
void CheckingAccount::withdrawMoney(double amount)
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
        cout << "Withdrew $" << fixed << setprecision(2) << amount << " from Account ID " << ID << ".\n";
    }
    else
    {
        double overdraftNeeded = amount - balance;

        if (overdraftNeeded <= overDraftLimit)
        {
            char confirm;
            cout << "Insufficient balance, but you can use overdraft.\n";
            cout << "Use $" << fixed << setprecision(2) << overdraftNeeded << " of overdraft (plus $20 fee)? (y/n): ";
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y')
            {
                if (overDraftLimit >= overdraftNeeded + 20)
                {
                    balance -= amount;
                    balance -= 20; // overdraft fee
                    overDraftLimit -= (overdraftNeeded + 20);
                    withdrawalCounter++;
                    cout << "Overdraft used. $" << amount << " withdrawn plus $20 fee. New balance: $" << balance
                        << ". Remaining overdraft limit: $" << overDraftLimit << "\n";
                }
                else
                {
                    cout << "Not enough overdraft limit available to cover fee. Withdrawal denied.\n";
                }
            }
            else
            {
                cout << "Withdrawal canceled.\n";
            }
        }
        else
        {
            cout << "Overdraft limit insufficient to cover this withdrawal.\n";
        }
    }
}

// PrintInfo override
void CheckingAccount::PrintInfo() const
{
    Account::PrintInfo();
    cout << "Overdraft Limit    : $" << fixed << setprecision(2) << overDraftLimit << "\n";
}
