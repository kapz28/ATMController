#include "Account.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

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
	if(account){
		if(amount>checkingAmount){
			cout << "\n\nYou don't have enough funds!" << endl;
			cout << "Please deposit more funds " << endl;
			return;
		}else{
			checkingAmount = checkingAmount-amount;
			cout << "\n\nSpitting bills out now" << endl;
			cout << "brrrrrrrrrrrrrrr!! " << endl;
			return;
		}
	}
	else{
		if(amount>savingsAmount){
			cout << "\n\nYou don't have enough funds!" << endl;
			cout << "Please deposit more funds " << endl;
			return;
		}else{
			savingsAmount = savingsAmount-amount;
			cout << "\n\nSpitting bills out now" << endl;
			cout << "brrrrrrrrrrrrrrr!! " << endl;
			return;
		}
	}
}

void  Account::deposit(int amount, int account)
{
	if(account){
		checkingAmount = checkingAmount+amount;
		cout << "\n\nYour amount has been deposited" << endl;
		cout << "new balance: " << checkingAmount << " $" << endl;
		return;

	}
	else{
		savingsAmount = savingsAmount+amount;
		cout << "\n\nYour amount has been deposited" << endl;
		cout << "new balance: " << savingsAmount << " $" << endl;
		return;
	}
}

void  Account::viewBalance(int account)
{
	if(account){
		cout << "\n\nYou funds are as follows:" << endl;
		cout << "checkingAmount balance" << endl;
		cout << checkingAmount << " $" << endl;
		return;
	}
	else{
		cout << "\n\nYou funds are as follows:" << endl;
		cout << "savingAmount balance" << endl;
		cout << savingsAmount << " $" << endl;
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