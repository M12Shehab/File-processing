#pragma once
#include "Account.h"
#include <vector>

class AccountsManger
{
private:
	int number_of_accounts;
	std::vector<Account*> accounts;
	bool is_found(std::string);
public:
	AccountsManger();
	~AccountsManger();

	//-----
	void add_account();
	void remove_account();
	void change_password();
	void display_all_accounts();
	int get_number_of_accounts();
	
};
