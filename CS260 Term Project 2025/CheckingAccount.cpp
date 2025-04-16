#include "CheckingAccount.h"
	// Constructors
	CheckingAccount::CheckingAccount() : Account()
	{
		overDraftLimit = 200;
	}
	CheckingAccount::CheckingAccount(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance,
		int _withdrawalCounter, int _depositsCounter, Customer _accountCustomer, double _overDraftLimit) : Account(_firstName, _lastName, _address, _phone, _email, _ID, _balance,
			_withdrawalCounter, _depositsCounter, _accountCustomer)
	{
		overDraftLimit = _overDraftLimit; 
	}
	// Setters
	void CheckingAccount::setOverDraftLimit(double _overDraftLimit)
	{
		overDraftLimit = _overDraftLimit; 
	}
	void CheckingAccount::setAll(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance,
		int _withdrawalCounter, int _depositsCounter, Customer _accountCustomer, double _overDraftLimit)
	{
		setOverDraftLimit(_overDraftLimit);
		_accountCustomer.setAll(_firstName, _lastName, _address, _phone, _email);
		Account::setAll(_firstName, _lastName, _address, _phone, _email, _ID, _balance, _withdrawalCounter, _depositsCounter, _accountCustomer);
		setAccountCustomer(_accountCustomer);
	}
	// Getters
	double CheckingAccount::getOverDraftLimit() const
	{
		return overDraftLimit;
	}
	// Functions
	void CheckingAccount::withdrawMoney(double amount)
	{
		if (balance < amount)
		{
			char opt = ' ';
			cout << "There is not enough Funds to withdraw $" << amount << " from Account ID: " << ID << endl;
			cout << "Would you like to use OverDraft? (Enter Y or N): " << endl;
			if (opt == 'y' || opt == 'Y')
			{
				if ((balance - amount) > overDraftLimit)
					balance -= (amount + 20); // $20 Overdraft Fee
				withdrawalCounter++;
				overDraftLimit -= 20;
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
		else if (balance == amount)
		{
			char opt = ' ';
			cout << "The Amount you are trying to Withdraw is equal to the amount in the Account. Would you Still like to Withdraw (Enter y or n)" << endl;
			if (opt == 'y' || opt == 'Y')
			{
				balance -= (amount + 20); // $20 Overdraft Fee
				overDraftLimit -= 20;
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
	