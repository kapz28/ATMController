#include <iostream>
#include <string>
#include "Account.h"
#include <limits>

// Kapilan Satkunanathan

using namespace std;

int chooseaccount()
{
    int r;
    bool valid = false;
    while(!valid){
        cout << "-----------------------------" << endl;
        cout << "|  Choose Account type   |" << endl;
        cout << "| 1 for checking   |" << endl;
        cout << "| 0 for savings   |" << endl;
        cout << "-----------------------------" << endl;
        cin >> r;
        if(!cin){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "\n\nERROR INVALID OPTION\n\n" << endl;
        }
        else if(r == 1 || r == 0){
            cout << "\n\nACCOUNT RETREIVED\n\n" << endl;
            valid = true;
            return r;
        }
    }
    return 0;
}

void Initialize(Admin bank){
    bank.createAccount(1234567890,1234,"Kapilan","Satkunanathan");
    bank.createAccount(1234567891,1235,"Bear","Robotics");
    bank.createAccount(1234567892,1236,"Elon","Musk");
}

int main()
{

    Admin bankofAmerica;
    Initialize(bankofAmerica);
    Account* myaccount = NULL;
    int accounttype  = 0;
    int accountnumber;
    int pin;
    bool validaccount = false;
    cout << "-----------------------------" << endl;
    cout << "|    Welcome to the ATM     |" << endl;
    cout << "|    BEARROBOTICS ATM       |" << endl;
    cout << "-----------------------------" << endl;

    while(!validaccount){
        cout << "-----------------------------" << endl;
        cout << "|  Enter your card number   |" << endl;
        cout << "| card # should be 10 digits|" << endl;
        cout << "|  mimics the card swipe    |" << endl;
        cout << "-----------------------------" << endl;
        cin >> accountnumber;
        if(!cin){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "\n\nERROR INVALID OPTION\n\n" << endl;
        }else{
            cout << "-----------------------------" << endl;
            cout << "|  Enter your pin   |" << endl;
            cout << "-----------------------------" << endl;
            cin >> pin;
            if(!cin){
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "\n\nERROR INVALID OPTION\n\n" << endl;
            }
            else{
                myaccount = bankofAmerica.retreiveAccount(accountnumber, pin);
                if(myaccount != NULL){
                    cout << "\n\nACCOUNT RETREIVED\n\n" << endl;
                    validaccount = true;
                }else{
                    cout << "\n\nACCOUNT NOT FOUND OR INVALID PIN\n\n" << endl;
                }
            }
        }


    }

    accounttype = chooseaccount();

    if(accounttype){
        cout << "\n\nchecking account selected\n\n" << endl;
    }else{
        cout << "\n\nsavings account selected\n\n" << endl;
    }

    bool exit = false;
    int option;
    while (!exit)
    {
        cout << "-----------------------------" << endl;
        cout << "|  What to do with Account   |" << endl;
        cout << "| 0 for withdraw   |" << endl;
        cout << "| 1 for deposit   |" << endl;
        cout << "| 2 to view balance   |" << endl;
        cout << "| 3 to logout   |" << endl;
        cout << "-----------------------------" << endl;
        cin >> option;
        if(!cin){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "\n\nERROR INVALID OPTION\n\n" << endl;
        }
        else{
            if(option == 0 || option == 1 || option == 2 || option == 3 ){
                int var;
                if (option == 0){
                    cout << "-----------------------------" << endl;
                    cout << "|  Enter Amount to Withdraw   |" << endl;
                    cout << "-----------------------------" << endl;
                    cin >> var;
                    if(!cin){
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "\n\nERROR INVALID OPTION\n\n" << endl;
                    }else{
                        myaccount->withdraw(var,accounttype);
                    }
                }else if(option == 1){
                    cout << "-----------------------------" << endl;
                    cout << "|  Enter Amount to Deposit   |" << endl;
                    cout << "-----------------------------" << endl;
                    cin >> var;
                    if(!cin){
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "\n\nERROR INVALID OPTION\n\n" << endl;
                    }else{
                        myaccount->deposit(var,accounttype);
                    }
                }else if (option == 2){
                    myaccount->viewBalance(accounttype);
                }else{
                    cout << "Card coming out" << endl;
                    cout << "LOGGED OUT!!" << endl;
                    exit = true;
                }

            }else{
                cout << "\n\nINVALID OPTION\n\n" << endl;
            }
        }
    }

    return 0;
}