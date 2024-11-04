#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;
class cls_Util
{
public:
	enum echartype
	{
		small = 1, capital = 2, digit = 3, random = 4, spical = 5


	};
	static void Srand()
	{
		srand((unsigned)time(NULL));
	}
	static int RandomNumber(int From, int To) {

		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}
	static void Swap(int& A, int& B)
	{
		int Temp;
		Temp = A; A = B;
		B = Temp;
	}
	static void Swap(string& A, string& B)
	{
		string Temp;
		Temp = A; A = B;
		B = Temp;
	}
	static void Swap(double& A, double& B)
	{
		double Temp;
		Temp = A; A = B;
		B = Temp;
	}
	static string  EncryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;
	}

	static string  DecryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text;
	}



	static char GetRandomCharacter(echartype CharType)
	{
		switch (CharType) {
		case echartype::small:
		{ return char(RandomNumber(97, 122)); break; }
		case echartype::capital:
		{ return char(RandomNumber(65, 90)); break; }
		case echartype::spical:
		{ return char(RandomNumber(33, 47)); break; }
		case echartype::digit:
		{ return char(RandomNumber(48, 57)); break; }
		case echartype::random:
		{ return char(RandomNumber(32, 126)); break; }

		}



	}
	static string GenerateWord(echartype CharType, short Length)
	{
		string Word;
		for (int i = 1; i <= Length; i++)
		{
			Word = Word + GetRandomCharacter(CharType);
		}
		return Word;
	}
	static string  GenerateKey()
	{
		string Key = "";
		Key = GenerateWord(echartype::capital, 4) + "-";
		Key = Key + GenerateWord(echartype::capital, 4) + "-";
		Key = Key + GenerateWord(echartype::capital, 4) + "-";
		Key = Key + GenerateWord(echartype::capital, 4);
		return Key;
	}
	static void GenerateKeys(short NumberOfKeys)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] : "; cout << GenerateKey() << endl;
		}
	}

	static 	void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = RandomNumber(1, 100);
	}

	static void FillArrayWithRandomword(string arr[100], int& arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateWord(echartype::random, 4);
	}

	static void ShuffleArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);

		}
	}

	static void ShuffleArray(string arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);

		}
	}
	static void FillArrayWithKeys(string arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateKey();
	}

	static string tabs(int numberoftabs)
	{
		string tabs = " ";
		for (int i = 0; i < numberoftabs; i++)
		{
			tabs = tabs + " ";
		}
		return tabs;
	}


	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}


	}

};

