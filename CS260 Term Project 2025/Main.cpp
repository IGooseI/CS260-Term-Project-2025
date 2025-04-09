#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Reminders:
// *Input Validation
// *Const on Getters



class Customer
{
	string firstName, lastName, address, phone, email;
	//int ID;
public:
	// Constructors
	Customer()
	{
		firstName = "";
		lastName = "";
		address = "";
		phone = "";
		email = "";
	}
	Customer(string _firstName, string _lastName, string _address, string _phone, string _email)
	{
		//ID = _ID;
		firstName = _firstName;
		lastName = _lastName;
		address = _address;
		phone = _phone;
		email = _email;
	}
	// Setters
	void setAll(string _firstName, string _lastName, string _address, string _phone, string _email)
	{
		//ID = _ID;
		firstName = _firstName;
		lastName = _lastName;
		address = _address;
		phone = _phone;
		email = _email;
	}
	/*void setID(int _ID)
	{
		ID = _ID;
	}*/
	void setFirstName(string _firstName)
	{
		firstName = _firstName;
	}
	void setLastName(string _lastName)
	{
		lastName = _lastName;
	}
	void setAddress(string _address)
	{
		address = _address;
	}
	void setPhone(string _phone)
	{
		phone = _phone;
	}
	void setEmail(string _email)
	{
		email = _email;
	}
	// Getters
	/*int getID() const
	{
		return ID;
	}*/
	string getFirstName() const
	{
		return firstName;
	}
	string getLastName() const
	{
		return lastName;
	}
	string getAddress() const
	{
		return address;
	}
	string getPhone() const
	{
		return phone;
	}
	string getEmail() const
	{
		return email;
	}
	// Functions
	void PrintInfo() const
	{
		cout << string(40, '=') << '\n';
		//cout << setw(25) << left << "Customer ID:" << ID << '\n';
		cout << setw(25) << left << "Name:" << firstName << " " << lastName << '\n';
		cout << setw(25) << left << "Email:" << email << '\n';
		cout << setw(25) << left << "Phone:" << phone << '\n';
		cout << setw(25) << left << "Address:" << address << '\n';
		cout << string(40, '=') << '\n';
	}
};
class Account : public Customer
{
	int ID;
	double balance;
	int withdrawalCounter = 0;
	int depositsCounter = 0;
	Customer accountCustomer;
public:
	// Constructors
	Account() : Customer()
	{
		ID = 0;
		balance = 0;
		withdrawalCounter = 0;
		depositsCounter = 0;
		accountCustomer.setAll("", "", "", "", "");

	}
	Account(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer _accountCustomer) : Customer(_firstName, _lastName, _address, _phone, _email)
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
	void setID(int _ID)
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
	void setBalance(double _balance)
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
	void setWithdrawalCounter(int _withdrawalCounter)
	{
		withdrawalCounter = _withdrawalCounter;
	}
	void setDepositsCounter(int _depositsCounter)
	{
		depositsCounter = _depositsCounter;
	}
	void setAccountCustomer(Customer _accountCustomer)
	{
		accountCustomer = _accountCustomer;
	}
	// Getters
	int getID() const
	{
		return ID;
	}
	double getBalance() const
	{
		return balance;
	}
	int getWithdrawalCounter() const
	{
		return withdrawalCounter;
	}
	int getDepositsCounter() const
	{
		return depositsCounter;
	}
	Customer getAccountCustomer() const
	{
		return accountCustomer;
	}
	// Functions
	void setAll(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer _accountCustomer)
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
	void depositMoney(double amount)
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
	void withdrawMoney(double amount)
	{
		if (balance < amount)
		{
			cout << "There is not enough Funds to withdraw $" << amount << " from Account ID: " << ID << endl;
		}
		else if (balance == amount)
		{
			char opt;
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
};
class CheckingAccount : public Account
{

public:

	// Constructors

	// Setters

	// Getters
};
class SavingAccount : public Account
{
public:
	// Constructors

	// Setters

	// Getters
};
int main()
{
	//Customer customer1{1, "Iver" , "Gustafson", "2800 University Blvd", "484-374-8955", "igustaf@jacksonville.edu"};
	//customer1.PrintInfo();

	return 0;
}