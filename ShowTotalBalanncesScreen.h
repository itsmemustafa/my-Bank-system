#pragma once
#include <vector>
#include <iostream>
#include "clsBankClient.h";
#include "cls_inputValidate.h";
#include "clsScreen.h";
#include <iomanip>
#include <string>
#include "ClsMainScreen.h"
#include "cls_Util.h"
class ShowTotalBalanncesScreen:public clsScreen
{private:
    static void _Print(clsBankClient Client)
    {

        cout << setw(25) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }
 
public:
 static  void ShowCtotalbalance()
    {


        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "\t  Balances List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(25) << left << "" << "\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;
        double totalbalance = clsBankClient::gettotalbalnces();
        if (vClients.size() == 0)
        {
            cout << "\t\t\t\tNo Clients Available In the System!";
        }
        else

        {    for(clsBankClient c: vClients)
        {
            _Print(c);
            cout << endl;
        }
            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n\n\n" << endl;
            cout << "the total balanceses = " << totalbalance << endl;
            cout << cls_Util::NumberToText(totalbalance) << endl;
        }
    }

};

