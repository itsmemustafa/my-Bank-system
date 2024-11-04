
#pragma once
#include <iostream>
#include "clsBankClient.h";
#include "clsScreen.h";
#include <iomanip>
#include <string>
#include "ClsUser.h"
using namespace std;
class ShowdeletUserinfo: public clsScreen
{private:
    static void _PrintUserRecordLine(clsUser User)
    {
        cout << "\nUSer Card\n";      
        cout << "\n___________________\n";
        cout << setw(8) << "UserName :" << User.UserName << endl;;
        cout << "Fullname :" << User.FullName() << endl;;
        cout << "PHone :" << User.Phone << endl;
        cout << "Email :" << User.Email << endl;
        cout << "Permissions :" << User.Permissions << endl;
        cout << "\n___________________\n";

    }
public:
    static void ShowDeleteUser()
    {        
        _DrawScreenHeader("delete User screen ");
        cout << "Enter Username To delete : ";
        string username=cls_InputValidate::ReadString();
        while (!clsUser::IsUserExist(username))
        {
            cout << "cant find this user to delete ,try another one : ";
            username = cls_InputValidate::ReadString();

        }
        clsUser c = clsUser::Find(username);
        char a = 'n';
        _PrintUserRecordLine(c);
        cout << "\n\n";
               cout << "are you sure you wnat to delete this User Y/N ? ";
        cin >> a;
        if (a == 'y' || a == 'Y')
        { if(c.Delete())
        {
            cout << "User deleted successfully :) .\n";
            _PrintUserRecordLine(c);
        }
        else { cout << "delete User faild :( .\n";
        }

        }

         


    }
};

