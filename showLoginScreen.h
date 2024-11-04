#pragma once
#include "Global.h"
#include "clsScreen.h"
#include "cls_InputValidate.h"
#include "clsMainScreen.h"
#include <fstream>
class showLoginScreen:public clsScreen
{private:
	
	static bool _login()
	{
		bool FailedLogin = false;
		int failedlogincounter = 0;
		string  username, password;
	
	
		do {
			if(FailedLogin)
			{
				failedlogincounter++;
				cout << "\n\nInvailed Username/Password \n\n";
				cout << "You have " << 3- failedlogincounter << " trails to logion .\n\n";
			}
			if(failedlogincounter==3)
			{
				cout << " you are locked after 3 failed login :(\n\n";
				return false;
			}
			cout << "\nEnter Username : ";
			username = cls_InputValidate::ReadString();
			cout << "\nEnter Password : ";
			password = cls_InputValidate::ReadString();

			CurrentUser = clsUser::Find(username, password);
			FailedLogin = CurrentUser.IsEmpty();
		
		
		}while (FailedLogin);
		 //save user register to file 
		CurrentUser.LouadUserRegisterToFile();

		//show main menue after login success 
			clsMainScreen::ShowMainMenue();
			return true;
		
		} 
public :
	static bool  ShowLogin()
	{
		system("cls");
		_DrawScreenHeader(" Login Screen ");
		clsDate date;
		return _login();

		
	
		

	}
};

