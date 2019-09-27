// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: w8_in_lab.cpp
// Version: 2.0
// Date: 2018/11/02
// Author: Chris Szalwinski, based on work by Heidar Davoudi
// Description:
// This file tests in_lab section of your workshop
//Name: Yuki Waka  Date: 07/18
///////////////////////////////////////////////////
#ifndef __SAVINGSACCOUNT_H__
#define __SAVINGSACCOUNT_H__
#include <iostream>
#include "Account.h"

namespace sict {
	class SavingsAccount : public Account {
		double Rate;
	public:
		SavingsAccount(double, double);
		void monthEnd();
		void display(std::ostream&) const;
	};
}
#endif
