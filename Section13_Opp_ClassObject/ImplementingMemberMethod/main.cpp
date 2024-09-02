/*

Implementing member methods
- Very similar to how we implemented functions
- Member methods have access to member attributes
+ So you don't need to pass them as arguments
- Can be implemented inside the class declaration
+ Need to use Class_name::method_name
- Can separate specification from implementation
+ .h file for the class declaration
+ .cpp file for the class implementation

*/

#include <iostream>

using namespace std;

/*
Inside the class declaration

class Account
{
private:
	double balance;
public:
	void set_balance(double bal)
	{
		balance = bal;
	}
	double get_balance()
	{
		return balance;
	}
};
*/

/*
Outside the class declaration

class Account
{
private:
	double balance;
public:
	void set_balance(double bal);
	double get_balance();
};

void Account::set_balance(double bal)
{
	balance = bal;
}
double Account::get_balance()
{
	return balance;
}
*/

/*

- Separating specification from implementation
+ For header file: Account.h
(1) Solution 1: use block guard
Include Guards
#ifndef _ACCOUNT_H_          : check to see if the preprocessor has a symbol named (check if a symbol has been defined)
#define _ACCOUNT_H_

// Account class declaration

#endif

Ex:
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

class Account
{
private:
	double balance;
public:
	void set_balance(double bal);
	double get_balance();
};

#endif

(2) Solution 2: use     #pragma once

#pragma once

class Account
{
private:
	double balance;
public:
	void set_balance(double bal);
	double get_balance();
};

+ For source file: Account.cpp
// System header files are included with no extension
// Include Account.h in double quotes. Include with angle brackets as in include istream used for system header files
// and compilers knows where these are located. Include with double quotes tell compiler to include header files that are
// local to this project, compilers also knows where those are

#include "Account.h"

void Account::set_balance (double bal)
{
	balance = bal;
}

double Account::get_balance()
{
	return balance;
}

*/

#include "Account.h""

int main()
{
	Account frank_account;
    frank_account.set_name("Frank's account");
    frank_account.set_balance(1000.0);
    if (frank_account.deposit(200))
    {
        cout << "Deposit OK" << endl;
    }
    else
    {
        cout << "Deposit not allowed" << endl;
    }

	return 0;
}
