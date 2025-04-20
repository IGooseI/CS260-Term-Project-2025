#include "Manager.h"

void Manager::setUsername(string _username)
{
	username = _username;
}
void Manager::setUserPassword(string _userPassword)
{
	userPassword = _userPassword;
}
Manager::Manager()
{
	username = "";
	userPassword = "";
}
Manager::Manager(string _username, string _userPassword)
{
	username = _username;
	userPassword = _userPassword;
}
string Manager::getUsername() const
{
	return username;
}
string Manager::getUserPassword() const
{
	return userPassword;
}
bool Manager::checkUserPassword(string _userPassword) const
{
	if (_userPassword == userPassword)
		return true;
	else
		return false;
}
void Manager::setAll(string _firstName, string _lastName, string _address, string _phone, string _email, int _ID, double _balance,
	int _withdrawalCounter, int _depositsCounter, Customer _accountCustomer, string _username, string _userPassword)
{
	Account::setAll(_firstName, _lastName, _address, _phone, _email, _ID, _balance, _withdrawalCounter, _depositsCounter, _accountCustomer);
	setUsername(_username);
	setUserPassword(_userPassword);
}