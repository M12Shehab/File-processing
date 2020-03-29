#pragma once
#include "Account.h"
#include <vector>

class AccountsManger
{
private:
	int number_of_accounts;
	std::vector<Account*> accounts;

public:
	AccountsManger();
	~AccountsManger();

	//-----
	void add_account();
	void remove_account();
	void display_all_accounts();
	int get_number_of_accounts();
	bool is_found(std::string);
};
