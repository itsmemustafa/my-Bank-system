#pragma once
#include <iostream>
#include "clsBankClient.h";
#include "cls_inputValidate.h";
#include "clsScreen.h";
#include <iomanip>
#include <string>
using namespace std;
class Showupdateclient:public clsScreen
{ private:
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
  static  void UpdateClient()
  {
      if (!checkaccesseright(clsUser::enPermissions::pUpdateClients))
      {
          return;
          //this return will end the function
      }


      _DrawScreenHeader(" Update screen ");
        string accountnumber = "";
        cout << "enter account number to update : ";
        accountnumber = cls_InputValidate::ReadString();
        while (!clsBankClient::isclientexist(accountnumber))
        {
            cout << "the account number you enterd is not exist enter again : ";
            accountnumber = cls_InputValidate::ReadString();
        }
        clsBankClient client = clsBankClient::find(accountnumber);
      _Print(client);

        cout << "\n\nUpdate Client Info:";
        cout << "\n____________________\n";

        _ReadClientInfo(client);
        clsBankClient::enSaveResult saveresult;
        saveresult = client.save();
        switch (saveresult)
        {
        case clsBankClient::Ssuccessed:

            cout << "\nAccount Updated Successfully :-)\n";
            _Print(client);
            break;
        case clsBankClient::SfaildEmptyObject:
            cout << "account was not saved because\n" << endl;
            break;
        default:
            break;
        }
    }

};

