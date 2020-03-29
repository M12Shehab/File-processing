// 
//
//  Lab session 10
//
//  Created by Mohammed Shehab on 3/29/20.
//  Copyright © 2020 Mohammed Shehab. All rights reserved.
//
#include "Account.h"
#include <iostream>
using namespace std;

Account::Account()
{
	this->account_id = "";
	this->password = "";
}

Account::Account(string id, string password)
{
	this->account_id = id;
	this->password = password;
}

Account::~Account()
{
	cout << "Account " << this->account_id << " log out.\n";
}

std::string Account::get_account_id()
{
	return this->account_id;
}

std::string Account::get_password()
{
	return this->password;
}

void Account::set_account_id(std::string id)
{
	this->account_id = id;
}

void Account::set_password(std::string p)
{
	this->password = p;
}
