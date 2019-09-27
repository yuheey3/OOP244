// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: w8_in_lab.cpp
// Version: 2.0
// Date: 2018/11/02
// Author: Chris Szalwinski, based on work by Heidar Davoudi
// Description:
// This file tests in_lab section of your workshop
//Name: Yuki Waka  Date: 07/20
///////////////////////////////////////////////////
#include "SavingsAccount.h" 
#include "ChequingAccount.h"
#include "Account.h"

namespace sict {

	const double interest = 0.05;
	const double transactionFee = 0.50;
	const double monthlyFee = 2.00;

	iAccount* CreateAccount(const char* type, double iniBalance)
	{
		bool check = false;
		iAccount* p;


		if (type[0] == 'S')
		{
			check = true;
			p = new SavingsAccount(iniBalance, interest);
		}
		else if (type[0] == 'C')
		{
			check = true;
			p = new ChequingAccount(iniBalance, transactionFee, monthlyFee);
		}
		return check ? p : nullptr;
	}
}