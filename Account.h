#pragma once
#include <string>
class Account
{
private:
	std::string account_id;
	std::string password;

public:
	Account();
	Account(std::string, std::string);
	~Account();

	//--------
	std::string get_account_id();
	std::string get_password();

	void set_account_id(std::string);
	void set_password(std::string);

};