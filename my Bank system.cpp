
#include <iostream>
#include "clsBankClient.h";
#include "cls_inputValidate.h";
#include "cls_Util.h";
#include "ClsMainScreen.h";
#include <iomanip>
#include "showLoginScreen.h"
using namespace std;

int main()
{//this while mean that the program will never stop ,so because of that every time you chose logout option it will start login again ,it will stop in one condtion if the while(false) and that wont happen .
	while (true)
	{
		if(!showLoginScreen::ShowLogin())
		{
			break;
		}
	}
}
