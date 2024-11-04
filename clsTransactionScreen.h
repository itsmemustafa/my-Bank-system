#pragma once
#include <iostream>
#include "clsBankClient.h";
#include "cls_inputValidate.h";
#include "clsScreen.h";
#include <iomanip>
#include <string>
#include "ClsMainScreen.h"
#include "clsdepsitscreen.h"
#include "clsWithdrawScreen.h"
#include "ShowTotalBalanncesScreen.h"
using namespace std;
class TransactionScreen:public clsScreen
{ private:
    enum etransactions
    {
        edeposit = 1, ewithdraw = 2, etotalbalnce = 3, emainmenue = 4

    };
   static void gobacktotransactionmenue()
   {
       cout << "press any kye to go back to transaction menue ..." << endl;
       system("pause>0");
       system("cls");
       showtransactionmenue();

   }
   static short readtransactionoption()
    {
        cout << "choose what do you want to do ?[1 to 4]  ";
        short choice = 0;
        choice=cls_InputValidate::readintnumberbetween(1,4,"enter number between 1 to 4 :");
        cin.ignore();
        return choice;
    }
   static void performtransactionmenue(etransactions trans)
    {
        switch (trans)
        {
        case etransactions::edeposit:
        {
            system("cls");
            show_deposit_screen();
            gobacktotransactionmenue();
            break;

        }
        case etransactions::ewithdraw:
        {
            system("cls");
            show_withdraw_screen();
            gobacktotransactionmenue();
            break;
        }
        case etransactions::etotalbalnce:
        {
            system("cls");
            show_total_balance();
            gobacktotransactionmenue();
            break;
        }
        case etransactions::emainmenue:
        {
            system("cls");
            cout << "i will add it later ";
            break;

        }
        }

    }
 
 static   void show_deposit_screen()
    {
     depsitscreen::showdepositscreen();
   }
 static  void show_withdraw_screen()
    {
     ShowwithdrawScreen::ShowWithdrawScreen();
    }
 static  void show_total_balance()
    {
     ShowTotalBalanncesScreen::ShowCtotalbalance();
    }
   
public:
   
 static  void showtransactionmenue()
    {
     if (!checkaccesseright(clsUser::enPermissions::pManageUsers))
     {
         return;
         //this return will end the function
     }
       _DrawScreenHeader("\t TRANSACTION Screen ");
       cout << setw(37) << left << "" << "===========================================\n";
       cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
       cout << setw(37) << left << "" << "===========================================\n";
       cout << setw(37) << left << "" << "\t[1] Deposit.\n";
       cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
       cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
       cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
       cout << setw(37) << left << "" << "===========================================\n";
        performtransactionmenue((etransactions)readtransactionoption());


    }
};


