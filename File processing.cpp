
#include <iostream>
#include "AccountsManager.h"

using namespace std;
int main()
{
    cout << "** Welcome to accounts manage system **\n";
    int menu_select = -1;
    AccountsManger manager = AccountsManger();
    do {
        cout << "** Main menu **\n";
        cout << "1- Create new account\n";
        cout << "2- Delete existing account\n";
        cout << "3- Display all accounts.\n";
        cout << "Enter your task id (1 to 3) to exit enter 0 or negative: ";
        cin >> menu_select;

        switch (menu_select)
        {
        case 1:manager.add_account(); break;
        case 2:manager.remove_account(); break;
        case 3:manager.display_all_accounts(); break;
        default:cout << "- Wronge task id, please enter (1,2 or 3).\n";
            break;
        }

    } while (menu_select>0);
    
}
/*
1- Read input from user.
2- Create file that holds file name as same user.
3- Now, ask user to enter password.
4- Open the file of current user.
5- Write that password into file.
6- Close the file.
7- Make option to user to check his password, change it and delete account.

8- Advanced, use Caesar Cipher
*/