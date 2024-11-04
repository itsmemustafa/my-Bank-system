#pragma once

#include <iostream>
#include "clsBankClient.h";
#include "cls_inputValidate.h";
#include "cls_Util.h";
#include "ClsMainScreen.h";
#include <iomanip>
#include "clsScreen.h"
#include "ShowUserslistScreen.h"
#include "ShowAddNewUserScreen.h"
#include "ShowdeletUserinfo.h"
#include "ShowUpdateUserScreen.h"
#include "ShowfindUserscreen.h"
using namespace std;
class ClsManageuUsersScreen: public clsScreen
{private:
    static   void gobackto_manage_menue()
    {
        cout << "press any kye to go back to manageusers menue ...";
        system("pause>0");
        show_manageusers_menue();


    }
    enum emanageusers
    {
        show = 1, add = 2, del = 3, update = 4,find=5, exite = 6

    };
    static  short read_manageusers_option()
    {
        cout << setw(37) << left << "" << "choose what do you want to do ?[1 to 6]  ";
        short choice = cls_InputValidate::readintnumberbetween(1, 6);
        cin.ignore();
        return choice;
    }
    static  void perform_manageusers_menue(emanageusers manage)
    {
        switch (manage)
        {
        case show:
            system("cls");
            showlistscreen();
            gobackto_manage_menue();
            break;
        case  emanageusers::add:
            system("cls");
            showaddscreen();
            gobackto_manage_menue();

            break;
        case  emanageusers::del:
            system("cls");
            showdeletescreen();
            gobackto_manage_menue();
            break;
        case  emanageusers::update:
            system("cls");
            showupdatescreen();
            gobackto_manage_menue();
            break;
        case emanageusers::find:
                system("cls");
                showfindscreen();
                gobackto_manage_menue();

        case emanageusers::exite:
            system("cls");
           // gobacktomainmenue();
        default:
            break;
        }



    }
  static  void showlistscreen()
    {
      ShowUsersScreen::ShowUsersList();
    }
  static  void showaddscreen()
    {
      ShowAddNewUserScreen::ShowAddNewuser();
    }
  static  void showdeletescreen()
    {
      ShowdeletUserinfo::ShowDeleteUser();
  }
  static void showupdatescreen()
    {
      ShowUpdateUserScreen::ShowUpdateUser();
    }
  static void showfindscreen()
  {
      ShowfindUserscreen::ShowfindUser();
  }



public:
  static  void show_manageusers_menue()
    {        

      if (checkaccesseright(clsUser::enPermissions::pManageUsers))
      {


          system("cls");
          _DrawScreenHeader("\t Manage Users Screen");

          cout << setw(37) << left << "" << "===========================================\n";
          cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
          cout << setw(37) << left << "" << "===========================================\n";
          cout << setw(37) << left << "" << "\t[1] List Users.\n";
          cout << setw(37) << left << "" << "\t[2] Add New User.\n";
          cout << setw(37) << left << "" << "\t[3] Delete User.\n";
          cout << setw(37) << left << "" << "\t[4] Update User.\n";
          cout << setw(37) << left << "" << "\t[5] Find User.\n";
          cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
          cout << setw(37) << left << "" << "===========================================\n";

          perform_manageusers_menue((emanageusers)read_manageusers_option());

 
      }
      else { return; }
      //this return will end the function 
  }

    
};

