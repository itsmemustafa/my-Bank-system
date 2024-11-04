#pragma once

#include <iostream>
#include "clsBankClient.h";
#include "cls_inputValidate.h";
#include "clsScreen.h";
#include <iomanip>
#include <string>
using namespace std;
class Showaddclientscreen : public clsScreen
{
private:
   static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = cls_InputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = cls_InputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = cls_InputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = cls_InputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = cls_InputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = cls_InputValidate::ReadfloatNumber();
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
    static void addclient()
    {
        if (!checkaccesseright(clsUser::enPermissions::pAddNewClient))
        {
            return;
            //this return will end the function
        }
        _DrawScreenHeader("Add client screen ");


        cout << "enter account number to add : ";
        string accountnumber = cls_InputValidate::ReadString();
        while (clsBankClient::isclientexist(accountnumber))
        {
            cout << "account number alrady used chose another one : ";
            accountnumber = cls_InputValidate::ReadString();

        }
        clsBankClient newclint = clsBankClient::getaddnewobject(accountnumber);
        _ReadClientInfo(newclint);
        clsBankClient::enSaveResult saveresult;
        saveresult = newclint.save();
        switch (saveresult)
        {
        case clsBankClient::Ssuccessed:
            cout << "addding the new client successed :) \n" << endl;
           _Print(newclint);
            break;
        case clsBankClient::SfaildEmptyObject:
            cout << "adding faild due to empty info :( \n" << endl;
            break;
        case clsBankClient::failedaccountnumberexist:
            cout << "adding new clint failed because the account number is used" << endl;
            break;
        default:
            break;
        }
    }
};

