#pragma once
#include "ClsUser.h"
#include "cls_InputValidate.h"
#include "clsScreen.h"

class ShowfindUserscreen:public clsScreen
{private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }
public:
    static void ShowfindUser()
    {
        _DrawScreenHeader(" Find USer Screen ");
        string username = "";
        cout << "Eter username to find : ";
        username = cls_InputValidate::ReadString();
        while (!clsUser::IsUserExist(username))
        {
            cout << "cant find this user try another one : ";
            username = cls_InputValidate::ReadString();
        }
        clsUser c = clsUser::Find(username);
        if (c.IsEmpty())
        {
            cout << "cant find this user :( \n\n";

        }
        else { _PrintUser(c); }
   }
};

