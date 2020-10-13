#pragma once
#include <string>
#include <vector>
#include "Account.h"
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