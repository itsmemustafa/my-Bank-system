#pragma once
#include <iostream>
#include "clsBankClient.h";
#include "cls_inputValidate.h";
#include "clsScreen.h";
#include <iomanip>
#include <string>
#include "ClsMainScreen.h"
using namespace std;
class ShowwithdrawScreen
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
    static void ShowWithdrawScreen()
    {
        string accountnumber;
        accountnumber = _Readaccountnumber();
        while (!clsBankClient::isclientexist(accountnumber))
        {
            cout << "account number not found try another one :";
            accountnumber = _Readaccountnumber();

        }
        clsBankClient c = clsBankClient::find(accountnumber);
        _Print(c);
        int amount = 0;
        cout << "\nenter the amount of withdraw :";
        amount = cls_InputValidate::ReadIntNumber();
        char a = 'n';
        cout << "are you sure you want to withdraw to this account Y/N ?";
        cin >> a;
        if (a == 'Y' || a == 'y')
        {
            if (c.withdraw(amount))

            {
                cout << "\nAmount withdraw Successfully.\n";
                cout << "\nnew balance after withdraw :\n" << c.AccountBalance << endl;
            }
            else {
                cout << "\nthere is'nt enough amount to withdraw :(\n";
                cout << "amount to withdraw is : " << amount << endl;
                cout << "the current balance is : " << c.AccountBalance << endl;
            }
        
        
        }
        else { cout << "\nwithdraw cancelled \n"; }


    }

    
};

