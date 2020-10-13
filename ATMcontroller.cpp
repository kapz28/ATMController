#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <stdio.h>

// Kapilan Satkunanathan

using namespace std;
class Account
{
    friend class Admin;
	private:
		string firstName, lastName;
		int accountNumber;
		int pinNumber;
        int checkingAmount;
        int savingsAmount;
        Account(int accountnumber, int pin,string firstname, string lastname);


	public:

		void withdraw(int amount, int account);
        void deposit(int amount, int account);
        void viewBalance(int account);
};

class Admin
{
	private:
        vector<Account> database;


	public:
        Admin();
        void createAccount(int accountnumber, int pin,string firstname, string lastname);
        Account* retreiveAccount(int account, int pin);
};

Account::Account(int accountnumbertemp, int pin,string firstnamevar, string lastnamevar)
{
	firstName = firstnamevar;
	lastName = lastnamevar;
	accountNumber = accountnumbertemp;
	pinNumber=pin;
	checkingAmount=0;
	savingsAmount = 0;
}

void  Account::withdraw(int amount, int account)
{
    if(amount < 0){
        cout << "\n\nInvalid Input" << endl;
        return;
    }
	if(account){
		if(amount>checkingAmount){
			cout << "\n\nYou don't have enough funds!" << endl;
			cout << "Please deposit more funds\n\n" << endl;
			return;
		}else{
			checkingAmount = checkingAmount-amount;
			cout << "\n\nSpitting bills out now" << endl;
			cout << "brrrrrrrrrrrrrrr!!\n\n" << endl;
			return;
		}
	}
	else{
		if(amount>savingsAmount){
			cout << "\n\nYou don't have enough funds!" << endl;
			cout << "Please deposit more funds\n\n" << endl;
			return;
		}else{
			savingsAmount = savingsAmount-amount;
			cout << "\n\nSpitting bills out now" << endl;
			cout << "brrrrrrrrrrrrrrr!!\n\n" << endl;
			return;
		}
	}
}

void  Account::deposit(int amount, int account)
{
    if(amount < 0){
        cout << "\n\nInvalid Input" << endl;
        return;
    }
	if(account){
		checkingAmount = checkingAmount+amount;
		cout << "\n\nYour amount has been deposited" << endl;
		cout << "new balance: " << checkingAmount << " $\n\n" << endl;
		return;

	}
	else{
		savingsAmount = savingsAmount+amount;
		cout << "\n\nYour amount has been deposited" << endl;
		cout << "new balance: " << savingsAmount << " $\n\n" << endl;
		return;
	}
}

void  Account::viewBalance(int account)
{
	if(account){
		cout << "\n\nYou funds are as follows:" << endl;
		cout << "checkingAmount balance" << endl;
		cout << checkingAmount << " $\n\n" << endl;
		return;
	}
	else{
		cout << "\n\nYou funds are as follows:" << endl;
		cout << "savingAmount balance" << endl;
		cout << savingsAmount << " $\n\n" << endl;
		return;
	}
}

Admin::Admin()
{

}

void Admin::createAccount(int accountnumber, int pin,string firstname, string lastname)
{
	Account created = Account(accountnumber,pin,firstname,lastname);
	database.push_back(created);
}

Account*  Admin::retreiveAccount(int account, int pin)
{
	if(database.empty()){
		return NULL;
	}
	for(int i = 0; i < database.size(); i++){
		if(database[i].pinNumber == pin && database[i].accountNumber == account){
			return &database[i];
		}
	}
	return NULL;
}

int chooseaccount()
{
    int r;
    bool valid = false;
    while(!valid){
        cout << "-----------------------------" << endl;
        cout << "|  Choose Account type   |" << endl;
        cout << "| 1 for checking   |" << endl;
        cout << "| 0 for savings   |" << endl;
        cout << "-----------------------------\n\n" << endl;
        cin >> r;
        if(!cin){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "\n\nERROR INVALID Input\n\n" << endl;
        }
        else if(r == 1 || r == 0){
            cout << "\n\nACCOUNT RETREIVED\n\n" << endl;
            valid = true;
            return r;
        }
    }
    return 0;
}

void initialize(Admin& bank){
    bank.createAccount(1234567890,1234,"Kapilan","Satkunanathan");
    bank.createAccount(1234567891,1235,"Bear","Robotics");
    bank.createAccount(1234567892,1236,"Elon","Musk");
}

int main()
{
    Admin bankofAmerica;
    initialize(bankofAmerica);
    Account* myaccount = NULL;
    int accounttype  = 0;
    int accountnumber;
    int pin;
    bool validaccount = false;
    cout << "-----------------------------" << endl;
    cout << "|    Welcome to the ATM     |" << endl;
    cout << "|    BEARROBOTICS ATM       |" << endl;
    cout << "-----------------------------\n\n" << endl;

    while(!validaccount){
        cout << "-----------------------------" << endl;
        cout << "|  Enter your card number   |" << endl;
        cout << "| card # should be 10 digits|" << endl;
        cout << "|  mimics the card swipe    |" << endl;
        cout << "-----------------------------\n\n" << endl;
        cin >> accountnumber;
        if(!cin){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "\n\nERROR INVALID INPUT\n\n" << endl;
        }else{
            cout << "-----------------------------" << endl;
            cout << "|  Enter your 4 digit pin   |" << endl;
            cout << "-----------------------------\n\n" << endl;
            cin >> pin;
            if(!cin){
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "\n\nERROR INVALID INPUT\n\n" << endl;
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
        cout << "| 4 to change accounts   |" << endl;
        cout << "-----------------------------\n\n" << endl;
        cin >> option;
        if(!cin){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "\n\nERROR INVALID INPUT\n\n" << endl;
        }
        else{
            if(option == 0 || option == 1 || option == 2 || option == 3 || option == 4){
                int var;
                if (option == 0){
                    cout << "-----------------------------" << endl;
                    cout << "|  Enter Amount to Withdraw   |" << endl;
                    cout << "-----------------------------\n\n" << endl;
                    cin >> var;
                    if(!cin){
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "\n\nERROR INVALID INPUT\n\n" << endl;
                    }else{
                        myaccount->withdraw(var,accounttype);
                    }
                }else if(option == 1){
                    cout << "-----------------------------" << endl;
                    cout << "|  Enter Amount to Deposit   |" << endl;
                    cout << "-----------------------------\n\n" << endl;
                    cin >> var;
                    if(!cin){
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "\n\nERROR INVALID INPUT\n\n" << endl;
                    }else{
                        myaccount->deposit(var,accounttype);
                    }
                }else if (option == 2){
                    myaccount->viewBalance(accounttype);
                }else if (option == 3){
                    cout << "Card coming out" << endl;
                    cout << "LOGGED OUT!!" << endl;
                    exit = true;
                }else{
                    accounttype = chooseaccount();
                    if(accounttype){
                        cout << "\n\nchecking account selected\n\n" << endl;
                    }else{
                        cout << "\n\nsavings account selected\n\n" << endl;
                    }
                }

            }else{
                cout << "\n\nINVALID INPUT\n\n" << endl;
            }
        }
    }

    return 0;
}

