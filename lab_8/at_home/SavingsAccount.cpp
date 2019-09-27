// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: w8_in_lab.cpp
// Version: 2.0
// Date: 2018/11/02
// Author: Chris Szalwinski, based on work by Heidar Davoudi
// Description:
// This file tests in_lab section of your workshop
//Name: Yuki Waka  Date: 07/20
///////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"

namespace sict
{
	SavingsAccount::SavingsAccount(double iniBalance, double rate)
	{
		if (iniBalance > 0)
			currBalance = iniBalance;
		else
			currBalance = 0.0;
		
		if (rate > 0)
			Rate = rate;
		else
			Rate = 0.0;
	}

	void SavingsAccount::monthEnd()
	{
		currBalance *= (Rate + 1);
		return;
	}

	void SavingsAccount::display(std::ostream& os) const{
	
		os << "Account type: Savings" << std::endl;
		os.unsetf(std::ios::floatfield);
		os.precision(2);
		os.setf(std::ios::fixed, std::ios::floatfield);
		os << "Balance: $" << balance() << std::endl;
		os << "Interest Rate (%): " << Rate * 100 << std::endl;
	}
}