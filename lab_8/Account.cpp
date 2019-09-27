// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: w8_in_lab.cpp
// Version: 2.0
// Date: 2018/11/02
// Author: Chris Szalwinski, based on work by Heidar Davoudi
// Description:
// This file tests in_lab section of your workshop
//Name: Yuki Waka  Date: 07/18
///////////////////////////////////////////////////
#include <iostream>
#include "iAccount.h"
#include "Account.h"

namespace sict
{
	Account::Account(double balance)
	{
		(balance) ?currBalance = balance : currBalance = 0;
	}

	bool Account::credit(double credit)
	{
		bool check = false;
		if (credit > 0) {
			check = true;
			currBalance += credit;
		}
		return check;
	}

	bool Account::debit(double debit)
	{
		bool check = false;
		if (debit > 0)
		{
			check = true;
			currBalance -= debit;
		}
		return check;
	}

	double Account::balance() const
	{
		return currBalance;
	}
}