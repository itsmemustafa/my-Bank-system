#pragma once
#pragma once
#include <iostream>
#include "clsBankClient.h";
#include "clsScreen.h";
#include <iomanip>
#include <string>
using namespace std;
class ShowAddNewUserScreen:public clsScreen
{private :

    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = cls_InputValidate::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = cls_InputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.Email = cls_InputValidate::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = cls_InputValidate::ReadString();

        cout << "\nEnter Password: ";
        User.Password = cls_InputValidate::ReadString();

        cout << "\nEnter Permission: ";
        User.Permissions = _ReadPermissionsToSet();
    }

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
    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        return Permissions;

    }
    public:
        static void ShowAddNewuser()
        {     _DrawScreenHeader("\t  Add New User Screen");
        cout<< "Enter the username :";
        string username = cls_InputValidate::ReadString();
        while (clsUser::IsUserExist(username))
        {
            cout << "this user is already exist try another one : ";
             username = cls_InputValidate::ReadString();


        }
        clsUser newuser = clsUser::GetAddNewUserObject(username);
        _ReadUserInfo(newuser);
        clsUser::enSaveResults saveresult = newuser.Save();
        switch (saveresult)
        {
        case clsUser::svFaildEmptyObject:
            cout << "faild to add the user :(" << endl;
            break;
        case clsUser::svSucceeded:
            cout << "the user added successefully :)" << endl;
            break;
        case clsUser::svFaildUserExists:
            cout << "faild to add the user :( the user is already exist " << endl;
            break;
        default:
            break;
        }
        



            }
};

