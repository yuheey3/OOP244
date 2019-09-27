// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: w8_in_lab.cpp
// Version: 2.0
// Date: 2018/11/02
// Author: Chris Szalwinski, based on work by Heidar Davoudi
// Description:
// This file tests in_lab section of your workshop
//Name: Yuki Waka  Date: 07/20
///////////////////////////////////////////////////
#ifndef __CHEQUINGACCOUNT_H__
#define __CHEQUINGACCOUNT_H__
#include "Account.h"

namespace sict {

	class ChequingAccount : public Account {
	private:
		double tranSaction;
		double monthFee;
	public:
		ChequingAccount(double, double, double);
		bool credit(double);
		bool debit(double);
		void monthEnd();
		void display(std::ostream&) const;
	};
}
#endif

