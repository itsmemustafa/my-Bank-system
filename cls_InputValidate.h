#pragma once
using namespace std;
#include <iostream>
#include "clsDate.h";
class cls_InputValidate
{
private:


public:
	short day;
	int month; int year;
	static bool isNumberbetween(int number, int from, int to)
	{
		if (number >= from && number <= to)
		{
			return true;
		}
		return false;
	}   
	static bool isNumberbetween(double number, double from, double to)
	{
		if (number >= from && number <= to)
		{
			return true;
		}
		return false;
	}
	clsDate date;
	static bool isdatebetween(clsDate date, clsDate datefrom, clsDate dateto)
	{

		//this if in case the input are reversed like instad of writeing (datefrom ,dateto) wrote (dateto,datefrom) it will swap them 
		if (clsDate::CompareDates(datefrom, dateto) == 1)
		{
			clsDate::SwapDates(datefrom, dateto);
		}



		if ((clsDate::CompareDates(date, dateto) == -1 || clsDate::CompareDates(date, dateto) == 0) && (clsDate::CompareDates(date, datefrom) == 1 || clsDate::CompareDates(date, datefrom) == 0))
		{
			return true;

		}
		return false;
	}
	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		int Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
	static double ReaddoubleNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
	static float ReadfloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		float Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
	static int readintnumberbetween(int from, int to, string message = "not within the range try again ")
	{
		int number = ReadIntNumber();

		while (!isNumberbetween(number, from, to))
		{
			cout << message;
			number = ReadIntNumber();

		}
		return number;
	}
	static	double readdoublenumberbetween(double from, double to, string message = "not within the range try again ")
	{
		double number = ReaddoubleNumber();

		while (!isNumberbetween(number, from, to))
		{
			cout << message;
			number = ReadIntNumber();

		}
		return number;
	}  
	static bool IsValidDate(clsDate date)
	{
		return clsDate::IsValidDate(date);

	}
	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract all the whitespace character
		getline(cin >> ws, S1);
		return S1;
	}

};


