#pragma once
#include <iostream>
#include "clsScreen.h";
#include "cls_inputValidate.h";
#include <iomanip>
#include "ShowclintListscreen.h"
#include "Showaddclientscreen.h"
#include "Showupdateclient.h"
#include "Showdeleteclient.h"
#include "showfindclient.h"
#include "clsTransactionScreen.h"
#include "ClsManageuUsersScreen.h"
#include "Global.h"
#include "ClsUser.h"
using namespace std;

class clsMainScreen :protected clsScreen
{


private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eExit = 8
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? ";
        short Choice = cls_InputValidate::readintnumberbetween(1, 8, "Enter Number between 1 to 8? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    { 
      
        ShowclintListscreen::ShowClientsList();
        _GoBackToMainMenue();

    }

    static void _ShowAddNewClientsScreen()
    {
        Showaddclientscreen::addclient();
        _GoBackToMainMenue();
    }

    static void _ShowDeleteClientScreen()
    {
        Showdeleteclient::Deleteclient();
        _GoBackToMainMenue();
    }

    static void _ShowUpdateClientScreen()
    {
        Showupdateclient::UpdateClient();
        _GoBackToMainMenue();

    }

    static void _ShowFindClientScreen()
    {
        showfindclient::findclient();
        _GoBackToMainMenue();
    }

    static void _ShowTransactionsMenue()
    {
    TransactionScreen::showtransactionmenue();

    }

    static void _ShowManageUsersMenue()
    {
        ClsManageuUsersScreen::show_manageusers_menue();

    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
        //this will back to main function 
        
        //ths will clear the global user and back to login screen
        // 
        //and it will give it a empty values so we can fill it again whene we login in angain 

    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();
            //Login();

            break;
        }

    }



public:


    static void ShowMainMenue()
    {

        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }

};
