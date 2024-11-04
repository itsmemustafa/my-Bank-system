#pragma once
#include <iostream>
#include "clsBankClient.h";
#include "cls_inputValidate.h";
#include "clsScreen.h";
#include <iomanip>
#include <string>
using namespace std;
class Showdeleteclient: public clsScreen 
{private :
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
public :
 static   void Deleteclient()
    {

     if (!checkaccesseright(clsUser::enPermissions::pDeleteClient))
     {
         return;
         //this return will end the function
     }
     _DrawScreenHeader("delete client screen ");

        string accountnumber = "";
        cout << "enter account number to delete : ";
        accountnumber = cls_InputValidate::ReadString();
        while (!clsBankClient::isclientexist(accountnumber))
        {
            cout << "the account number you enterd is not exist enter again : ";
            accountnumber = cls_InputValidate::ReadString();
        }
        clsBankClient clienttodelete = clsBankClient::find(accountnumber);
        _Print(clienttodelete);
        cout << "\n\n\n\n";
        char answare = 'n';
        cout << "are you sure you want to delete this client ? y/n :";
        cin >> answare;
        if (answare == 'y' || answare == 'Y')
        {
            if (clienttodelete.Delete())
            {
                cout << "clint deleted successfully :) \n";
                _Print(clienttodelete);
            }
            else
            {
                cout << "delete client cancelled :O \n";

            }
        }
    }

};

