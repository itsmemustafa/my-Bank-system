#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "cls_person.h";
#include "clsString.h";
#include <vector>

#include <iostream>
#include "cls_inputValidate.h";
using namespace std;



class clsBankClient : public cls_person
{
private:

    // i putted them here cuz i don't need them to appear in menu and with that i applied (abstract)
    static clsBankClient _ConvertLinetoClientObject(string line, string delima)
    {
        vector<string>c;
        c = clsString::Split(line, delima);
        return clsBankClient(enMode::UpdateMode, c[0], c[1], c[2], c[3], c[4], c[5], stof(c[6]));
    }
    static string _convertClientObjecttoLine(clsBankClient c)
    {
        string sword = "";
        string d = "#//#";
        sword += c.FirstName + d;
        sword += c.LastName + d;
        sword += c.Email + d;
        sword += c.Phone + d;
        sword += c.AccountNumber() + d;
        sword += c.PinCode + d;
        sword += to_string(c.AccountBalance);
        return sword;

    }
    static vector<clsBankClient> _loudclientdatafromfile()
    {
        vector<clsBankClient>c;
        fstream myfile;
        myfile.open("Clients.txt", ios::in);

        if (myfile.is_open())
        {
            string line;
            while (getline(myfile, line))
            {
                clsBankClient client = _ConvertLinetoClientObject(line, "#//#");
                c.push_back(client);


            }

            myfile.close();
        }
        return c;
    }
    static void _saveclintdatatofile(vector < clsBankClient>client)
    {
        fstream myfile;
        myfile.open("Clients.txt", ios::out);
        if (myfile.is_open())
        {
            for (clsBankClient c : client)
            {
                if (c._markfordelete == false)
                {
                    string line = _convertClientObjecttoLine(c);
                    myfile << line << endl;
                }
            }
        }

    }

    void _update()
    {
        vector<clsBankClient>client;
        client = _loudclientdatafromfile();
        for (clsBankClient& c : client)
        {
            if (c.AccountNumber() == AccountNumber())
            {
                c = *this;
                break;
            }

        }
        _saveclintdatatofile(client);
    }
    void _Addnew()
    {
        _Addlinetofile(_convertClientObjecttoLine(*this));
    }

    void _Addlinetofile(string line)
    {
        fstream myfile;
        myfile.open("Clients.txt", ios::app | ios::out);
        if (myfile.is_open())
        {
            myfile << line << endl;


        }
        myfile.close();

    }
    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

public:
    //we need it in login 
    enum enMode { EmptyMode = 0, UpdateMode = 1, AddnewMode = 2 };
    enMode _Mode;


    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _markfordelete = false;

    clsBankClient(enMode mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string Pincode, float AccountBalance) : cls_person(FirstName, LastName, Email, Phone)
    {
        _Mode = mode;
        _AccountNumber = AccountNumber;
        _PinCode = Pincode;
        _AccountBalance = AccountBalance;


    }

    bool isEmpty()
    {
        return(_Mode == enMode::EmptyMode);
    }

    //set & get  
    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    //
    static  clsBankClient find(string AccountNumber)
    {
        fstream myfile;
        myfile.open("Clients.txt", ios::in);

        if (myfile.is_open())
        {
            string line;
            while (getline(myfile, line))
            {
                clsBankClient c = _ConvertLinetoClientObject(line, "#//#");
                if (c._AccountNumber == AccountNumber)
                {
                    return c;
                    myfile.close();
                }

                ;

            }
            myfile.close();
        }
        //incase we did'nt find the clinet in file we will return empty 
        return _GetEmptyClientObject();
    }

    static  clsBankClient find(string AccountNumber, string pincode)
    {
        fstream myfile;
        myfile.open("Clients.txt", ios::in);

        if (myfile.is_open())
        {
            string line;
            while (getline(myfile, line))
            {
                clsBankClient c = _ConvertLinetoClientObject(line, "#//#");
                if (c._AccountNumber == AccountNumber && c._PinCode == pincode)
                {
                    return c;
                    myfile.close();
                }


            }
            myfile.close();
        }
        //incase we did'nt find the clinet in file we will return empty 
        return _GetEmptyClientObject();
    }

    static bool  isclientexist(string accountnumber)
    {
        clsBankClient client = clsBankClient::find(accountnumber);
        return (!client.isEmpty());

    }
    enum enSaveResult {
        Ssuccessed = 0, SfaildEmptyObject = 1, failedaccountnumberexist = 2

    };
    enSaveResult save()
    {
        switch (_Mode)
        {
        case clsBankClient::EmptyMode:
        {
            return enSaveResult::SfaildEmptyObject;
            break;
        }
        case clsBankClient::UpdateMode:
        {
            _update();
            return enSaveResult::Ssuccessed;
            break;
        }
        case clsBankClient::AddnewMode:
        {
            if (clsBankClient::isclientexist(_AccountNumber))
            {
                return enSaveResult::failedaccountnumberexist;
            }
            else
            {
                _Addnew();
                _Mode = enMode::UpdateMode;
                return enSaveResult::Ssuccessed;

            }
        }

        default:
            break;
        }


    }
    bool Delete() {
        vector<clsBankClient>client;
        client = _loudclientdatafromfile();
        for (clsBankClient& c : client)
        {
            if (c.AccountNumber() == AccountNumber())
            {
                c._markfordelete = true;
                break;
            }
        }
        _saveclintdatatofile(client);
        *this = _GetEmptyClientObject();
        return true;
    }
    static clsBankClient getaddnewobject(string accountnumber)
    {
        return clsBankClient(enMode::AddnewMode, " ", " ", " ", " ", accountnumber, " ", 0);
    }
    static vector<clsBankClient>  GetClientsList()
    {
        return _loudclientdatafromfile();

    }
     void deposit(int amount)
    { 
        AccountBalance= AccountBalance + amount;
        save();
    }
     bool withdraw(int amount)
     { if(AccountBalance<amount)
     {
         return false;
     }
     else {
         AccountBalance -= amount;
         save();
         return true;
     }
     }
     static int gettotalbalnces()
     {
         int totabalnce=0;
         vector<clsBankClient> vClients = _loudclientdatafromfile();
         for (clsBankClient Client : vClients)
         {
             totabalnce += Client.AccountBalance;

             cout << endl;
         }
         return totabalnce;
     }
};