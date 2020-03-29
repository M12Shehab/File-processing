// 
//
//  Lab session 10
//
//  Created by Mohammed Shehab on 3/29/20.
//  Copyright © 2020 Mohammed Shehab. All rights reserved.
//
#include "AccountsManager.h"
#include <fstream>
#include <iostream>
#include "Cipher.h"
using namespace std;

AccountsManger::AccountsManger()
{
	try {
		// Create Manager.txt as meta data file
		ifstream file_manager("Manager.txt", ios::in); // opens file
		if (!file_manager)
		{
			throw -1;
		}
		string line; // Temp string buffer to read data from file.
		// Continue as normal and read data.

		while (getline(file_manager, line))
		{
			cout <<">> Account Id# "<< line << '\n';
			// I got the account file that contains the password.
			// I need to open and load its password.
			ifstream file_account(line, ios::in);
			try
			{
				string password;
				getline(file_account, password);
				Cipher c = Cipher();
				c.set_text_cipher(password);
				c.caesar_cipher();
				// The file always contains one line.
				Account* account = new Account(line, c.get_text_orignal());
				this->accounts.push_back(account);
				file_account.close();
			}
			catch (...)
			{
				cout << "- Account Id# " << line << " data is not found.\n";
			}
		}
		file_manager.close();
	}
	catch (int err)
	{
		cout << "- File \"Manager.txt\" could not be found.\n";
		cout << "+ Trying to create new meat-data file.\n";
		ofstream file_manager("Manager.txt", ios::out);
		if (file_manager.is_open())
		{
			file_manager.close();
			cout << "+ File \"Manager.txt\" created.\n";
		}
		else 
			cout << "- Unable to open file.\n";
	}
	this->number_of_accounts = this->accounts.size();
}

AccountsManger::~AccountsManger()
{
	ofstream file_manager("Manager.txt", ios::out);
	for (auto a : this->accounts)
	{
		file_manager << a->get_account_id() + "\n";
		a = nullptr;
	}
	file_manager.close();
	this->accounts.clear();
	cout << "+ Exit from program.\n";
}

void AccountsManger::add_account()
{
	// We need two attribtus (account id and its password)
	string account_id, password;
	// Enter account id
	cout << "Enter account Id: ";
	cin >> account_id;
	// Check if that id is uniqe or not.
	if (this->is_found(account_id))
	{
		//cout << "- Sorry this user id is already used.\n";
		cout << "- Sorry an error!! (Try again..).\n";
		return;
	}
	// Enter password.
	cout << "+ User id is valid.\n";
	do
	{
		cout << "Enter password: ";
		cin >> password;
	} while (password.size() <= 0);

	string re_password;
	cout << "Re-enter password: ";
	cin >> re_password;
	if (password == re_password)
	{
		Cipher c = Cipher();
		c.set_text_orignal(password);
		c.caesar_cipher();
		// create new file holds account id as name
		ofstream myfile(account_id + ".txt");
		// Write password inside it.
		myfile << c.get_text_cipher();
		// Close that file.
		myfile.close();
		// Create object and add the new file to the list.
		Account* account = new Account(account_id + ".txt", password);
		this->accounts.push_back(account);
		this->number_of_accounts = this->accounts.size();
		cout << "+ User id " << account_id << " is created.\n";
	}
	else
	{
		cout << "- Sorry the password does not matched.\n";
	}
}

void AccountsManger::remove_account()
{
	string account_id, password;
	// Enter account id
	cout << "Enter account Id: ";
	cin >> account_id;
	// Check if that id is uniqe or not.
	account_id += ".txt";
	if (!this->is_found(account_id))
	{
		cout << "- Sorry an error!! (Try again..).\n";
		return;
	}
	
	for (int pos = 0; pos < accounts.size(); pos++)
	{
		if (accounts[pos]->get_account_id() == account_id )
		{
			cout << "Please enter password of account ( " << account_id << " ) to delete: ";
			cin >> password;
			if (password == accounts[pos]->get_password())
			{
				// remove file
				const char* file_name = account_id.c_str();
				int delete_flag = remove(file_name); // delete file
				if (delete_flag == 0)
				{
					accounts[pos] = accounts[accounts.size() - 1];
					accounts[accounts.size() - 1] = nullptr;
					accounts.pop_back();
					cout << "+ Account with id = " << account_id << " deleted." << endl;
				}
				else
				{
					cout << "- Error while delete file " << file_name << ".\n";
				}
			}
			else {
				cout << "- Wrong password.\n";
			}
			break;
		}
	}
}

void AccountsManger::display_all_accounts()
{
	for (auto a : this->accounts)
	{
		cout <<"Account id# " << a->get_account_id() + "\n";
	}
	cout << "\n-------------------------\n";
}

int AccountsManger::get_number_of_accounts()
{
	return this->number_of_accounts;
}

bool AccountsManger::is_found(string account_id)
{
	for (auto a : this->accounts)
	{
		if (a->get_account_id() == account_id)
		{
			return true;
		}
	}
	return false;
}
