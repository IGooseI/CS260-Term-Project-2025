#include "Account.h"

// Constructors
Account::Account() : Customer()
{
	ID = 0;
	balance = 0;
	withdrawalCounter = 0;
	depositsCounter = 0;
	accountCustomer.setAll("", "", "", "", "");

}
Account::Account(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer _accountCustomer) : Customer(_firstName, _lastName, _address, _phone, _email)
{
	if (ID >= 0 && ID <= 999)
	{
		ID = _ID;
	}
	else
	{
		cout << "ID is Invalid. Will be set to -1, Please Change." << endl;
		ID = -1;
	}
	if (balance < 0)
	{
		cout << "Balance is Invalid." << endl;
		balance = 0;
	}
	else
		balance = _balance;
	withdrawalCounter = _withdrawalCounter;
	depositsCounter = _depositsCounter;
	accountCustomer.setAll(_firstName, _lastName, _address, _phone, _email);

}
// Setters
void Account::setID(int _ID)
{
	if (ID >= 0 && ID <= 999)
	{
		ID = _ID;
	}
	else
	{
		cout << "ID is Invalid. Will be set to -1, Please Change." << endl;
		ID = -1;
	}
}
void Account::setBalance(double _balance)
{
	if (balance < 0)
	{
		cout << "Balance is Invalid." << endl;
		balance = 0;
	}
	else
	{
		balance = _balance;
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
void Account::setAccountCustomer(Customer _accountCustomer)
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
Customer Account::getAccountCustomer() const
{
	return accountCustomer;
}
// Functions
void Account::setAll(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer _accountCustomer)
{
	if (ID >= 0 && ID <= 999)
	{
		ID = _ID;
	}
	else
	{
		cout << "ID is Invalid. Will be set to -1, Please Change." << endl;
		ID = -1;
	}
	if (balance < 0)
	{
		cout << "Balance is Invalid." << endl;
		balance = 0;
	}
	else
		balance = _balance;
	withdrawalCounter = _withdrawalCounter;
	depositsCounter = _depositsCounter;
	accountCustomer.setAll(getFirstName(), getLastName(), getAddress(), getPhone(), getEmail());
}
void Account::depositMoney(double amount)
{
	if (amount < 0)
	{
		cout << "Cannot Deposit less than 0." << endl;
	}
	else
	{
		balance += amount;
		depositsCounter++;
		cout << "You've Successfully Deposited $" << amount << " into the Account ID: " << ID << endl;
	}
}
void Account::withdrawMoney(double amount)
{
	if (balance < amount)
	{
		cout << "There is not enough Funds to withdraw $" << amount << " from Account ID: " << ID << endl;
	}
	else if (balance == amount)
	{
		char opt = ' ';
		cout << "The Amount you are trying to Withdraw is equal to the amount in the Account. Would you Still like to Withdraw (Enter y or n)" << endl;
		if (opt == 'y' || opt == 'Y')
		{
			balance -= amount;
			withdrawalCounter++;
			cout << "You've successfully Withdrawn $" << amount << "from Account ID: " << ID << endl;
			cout << "Your balance is now: $" << balance << endl;
		}
		else if (opt == 'n' || opt == 'N')
		{
			cout << "Okay... Your Balance is: $" << balance << endl;
			return;
		}
		else
		{
			cout << "Invalid Entry..." << endl;
			return;
		}
	}
	else if (balance >= amount)
	{
		balance -= amount;
		withdrawalCounter++;
		cout << "You've successfully Withdrawn $" << amount << "from Account ID: " << ID << endl;
		cout << "Your balance is now: $" << balance << endl;
	}
}