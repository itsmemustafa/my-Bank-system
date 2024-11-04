#pragma once
#include <iostream>
#include "clsBankClient.h";
#include "cls_inputValidate.h";
#include "clsScreen.h";
#include <iomanip>
#include <string>
#include "ClsMainScreen.h"
using namespace std;
class depsitscreen:public clsScreen
{private:
    static string _Readaccountnumber()
    {
        string accountnumber;

        cout << "\nEnter Account number to deposit : ";
        cin >> accountnumber;
        return  accountnumber;
    }
    static void _Print(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
public:
    static void showdepositscreen()
    {
        string accountnumber;
        accountnumber = _Readaccountnumber();
        while (!clsBankClient::isclientexist(accountnumber))
        {
            cout << "cant find this account number , anter another account number : ";
            accountnumber = _Readaccountnumber();

        }

        clsBankClient c = clsBankClient::find(accountnumber);
        _Print(c);
        int amount = 0;
        cout << "Enter deposit amount :";
        amount = cls_InputValidate::ReadIntNumber();
       
        char a = 'n';
        cout << "are you sure you want to deposit to this account Y/N ?";
        cin >> a;
        if (a == 'Y' || a == 'y')
        {
            c.deposit(amount);
            cout << "\nAmount Deposited Successfully.\n";
        
            cout << "\nnew balance after deposit :\n" << c.AccountBalance <<endl;;
        }
        else { cout << "\ndeposit cancelled \n"; }
      

    }

};

