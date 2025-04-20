#include "PasswordSystem.h"

void PasswordSystem::setPassword(string _password)
	{
		password = _password;
	}
PasswordSystem::PasswordSystem()
	{
		password = "";
	}
PasswordSystem::PasswordSystem(string _password)
	{
		password = _password;
	}
string PasswordSystem::getPassword() const
{
	return password;
}
bool PasswordSystem::checkPassword(string _password) const
{
	if (_password == password)
		return true;
	else
		return false;
}

