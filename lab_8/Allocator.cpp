// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: w8_in_lab.cpp
// Version: 2.0
// Date: 2018/11/02
// Author: Chris Szalwinski, based on work by Heidar Davoudi
// Description:
// This file tests in_lab section of your workshop
//Name: Yuki Waka  Date: 07/18
///////////////////////////////////////////////////
#include "SavingsAccount.h" 

namespace sict {

	const double interest = 0.05;

	iAccount* CreateAccount(const char* type, double iniBalance)
	{
		bool check = false;
		iAccount* p;

		if (type[0] == 'S')
		{
			check = true;
			p = new SavingsAccount(iniBalance, interest);
		}
		return check ? p : nullptr;
	}
}