// ================= MAIN.CPP =================
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Customer.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "PasswordSystem.h"
#include "Manager.h"
using namespace std;

int main()
{
    const int MAX_NUM = 100;
    const int MAX_NUM_C = 200;
	const double MAX_OVERDRAFT = 200.0;
	const double MAX_INTEREST_RATE = 0.05;
    Customer customerList[MAX_NUM_C];
    CheckingAccount customerChecking[MAX_NUM];
    SavingAccount customerSaving[MAX_NUM];
    Manager admin("admin", "admin123");

    int choice = 0;
    int countCustomer = 0;
    int countChecking = 0;
    int countSaving = 0;
    string _firstName, _lastName, _address, _phone, _email;
    int _ID, _withdrawalCounter, _depositsCounter;
    double _balance, transferAmount;
    int viewID;
	string username, password;

    do
    {
        cout << "\n" << setw(30) << setfill('=') << "=" << endl;
        cout << "\n" << setfill(' ') << setw(20) << left << "Banking System Menu" << endl;
        cout << setw(30) << setfill('-') << "-" << endl;
        cout << "1. Create Checking Account" << endl;
        cout << "2. Create Saving Account" << endl;
        cout << "3. Modify Account (Deposit/Withdraw)" << endl;
        cout << "4. View Account" << endl;
        cout << "5. Transfer Funds Between Saving Accounts" << endl;
        cout << "6. Apply Interest to Saving Accounts" << endl;
        cout << "7. Enter Manager View" << endl;
        cout << "8. Exit Program" << endl;
        cout << setw(30) << setfill('=') << "=" << "\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            if (countChecking >= MAX_NUM) {
                cout << "Error: Maximum number of customers reached.\n";
                break;
            }
            cout << "Enter First Name: "; getline(cin, _firstName);
            cout << "Enter Last Name: "; getline(cin, _lastName);
            cout << "Enter Address: "; getline(cin, _address);
            cout << "Enter Phone number: "; getline(cin, _phone);
            cout << "Enter Email: "; getline(cin, _email);
            cout << "Enter ID: "; cin >> _ID;
            cout << "Enter Balance: "; cin >> _balance;
            customerList[countCustomer].setAll(_firstName, _lastName, _address, _phone, _email);
            customerChecking[countChecking].setAll(_ID, _balance, 0, 0, &customerList[countCustomer], MAX_OVERDRAFT);
            countCustomer++;
            countChecking++;
            system("pause");
            system("cls");
            break;

        case 2:
            if (countSaving >= MAX_NUM) {
                cout << "Error: Maximum number of customers reached.\n";
                break;
            }
            cout << "Enter First Name: "; getline(cin, _firstName);
            cout << "Enter Last Name: "; getline(cin, _lastName);
            cout << "Enter Address: "; getline(cin, _address);
            cout << "Enter Phone number: "; getline(cin, _phone);
            cout << "Enter Email: "; getline(cin, _email);
            cout << "Enter ID: "; cin >> _ID;
            cout << "Enter Balance: "; cin >> _balance;
            customerList[countCustomer].setAll(_firstName, _lastName, _address, _phone, _email);
            customerSaving[countSaving].setAll(_ID, _balance, 0, 0, &customerList[countCustomer], MAX_INTEREST_RATE);
            countCustomer++;
            countSaving++;
            system("pause");
            system("cls");
            break;

        case 3:
            cout << "Enter Account ID: "; cin >> _ID;
            cout << "1. Deposit\n2. Withdraw\nEnter Option: ";
            int action; cin >> action;
            cout << "Enter Amount: "; cin >> transferAmount;
            for (int i = 0; i < countChecking; ++i)
            {
                if (customerChecking[i].getID() == _ID)
                {
                    if (action == 1) customerChecking[i].depositMoney(transferAmount);
                    else customerChecking[i].withdrawMoney(transferAmount);
                }
            }
            for (int i = 0; i < countSaving; ++i)
            {
                if (customerSaving[i].getID() == _ID)
                {
                    if (action == 1) customerSaving[i].depositMoney(transferAmount);
                    else customerSaving[i].withdrawMoney(transferAmount);
                }
            }
            system("pause");
            system("cls");
            break;

        case 4:
            cout << "Enter Account ID: "; cin >> viewID;
            for (int i = 0; i < countChecking; ++i)
            {
                if (customerChecking[i].getID() == viewID)
                {
                    customerChecking[i].PrintInfo();
                }
            }
            for (int i = 0; i < countSaving; ++i)
            {
                if (customerSaving[i].getID() == viewID)
                {
                    customerSaving[i].PrintInfo();
                }
            }
            system("pause");
            system("cls");
            break;

        case 5:
            cout << "Enter Source Account ID: ";
            int srcID, dstID;
            cin >> srcID;
            cout << "Enter Destination Account ID: ";
            cin >> dstID;
            cout << "Enter Amount: ";
            cin >> transferAmount;
            for (int i = 0; i < countSaving; ++i)
            {
                if (customerSaving[i].getID() == srcID)
                {
                    for (int j = 0; j < countSaving; ++j)
                    {
                        if (customerSaving[j].getID() == dstID)
                        {
                            customerSaving[i].transfer(transferAmount, customerSaving[j]);
                        }
                    }
                }
            }
            system("pause");
            system("cls");
            break;

        case 6:
            for (int i = 0; i < countSaving; ++i)
            {
                customerSaving[i].payInterestRate();
            }
            cout << "Interest applied to all saving accounts.\n";
            system("pause");
            system("cls");
            break;

        case 7:
            cout << "\n=== Manager View Login ===\n";
            cout << "Enter Manager Username: ";
            getline(cin, username);
            cout << "Enter Password: ";
            getline(cin, password);
            if (admin.getUsername() == username)
            {
                if (admin.checkUserPassword(password))
                {
                    cout << "\n--- Manager Mode Activated ---\n";
                    for (int i = 0; i < countChecking; ++i)
                    {
                        customerChecking[i].PrintInfo();
                    }
                    for (int i = 0; i < countSaving; ++i)
                    {
                        customerSaving[i].PrintInfo();
                    }
                    cout << "--- End of Manager View ---\n";
                }
                else
                {
                    cout << "Invalid password.\n";
                }
            }
            else
            {
                cout << "Invalid username.\n";
            }
            system("pause");
            system("cls");
            break;

        case 8:
            cout << "Exiting program.\n";
            system("pause");
            system("cls");
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            system("pause");
            system("cls");       
}

    } while (choice != 8);
    system("pause");
    system("cls");

    return 0;
}
