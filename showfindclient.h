#pragma once
#include <iostream>
#include "clsBankClient.h";
#include "cls_inputValidate.h";
#include "clsScreen.h";
#include <iomanip>
#include <string>
using namespace std;
class showfindclient:public clsScreen
{ private:
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
    static void findclient()
    {
        if (!checkaccesseright(clsUser::enPermissions::pFindClient))
        {
            return;
            //this return will end the function
        }
        _DrawScreenHeader("find client screen ");

        string accountnumber;
        cout << "enter account number to find : ";
        accountnumber=cls_InputValidate::ReadString();
        while (!clsBankClient::isclientexist(accountnumber))
        {
            cout << "this account not found pleas try another one :";
            accountnumber = cls_InputValidate::ReadString();

        }

        clsBankClient c=clsBankClient::find(accountnumber);
        if (c.isEmpty())
        {
            cout << "not found :(" << endl;
        }
        else {
            _Print(c);
        }


    }


};

