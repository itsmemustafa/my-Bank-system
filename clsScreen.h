#pragma once
#include <iostream>
#include "ClsUser.h"
#include "Global.h"
#include "clsDate.h"
//this library just for showing the header , i made it library so so i can use the function diffrent times whith multi tabls names
// and it also used to check the accesse perimssion rights 
using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {   
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\n\t\t\t\t\t  User : "<<CurrentUser.UserName;;
        
        cout << "\n\t\t\t\t\t  Date : ";
        clsDate todaysdate;
        todaysdate.Print();



        cout << "\n\n";
    }
  static bool checkaccesseright(clsUser::enPermissions permission)
    { //if he dosent have the accesse oon this operation 
        if (!CurrentUser.checkUserPermission(permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        } 
        // if the user have access on this operation 
        else { return true; }
    }

};

