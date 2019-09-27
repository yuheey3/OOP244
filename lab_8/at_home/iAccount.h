// Workshop 8 - Virtual Functions and Abstract Base Classes
// File: w8_in_lab.cpp
// Version: 2.0
// Date: 2018/11/02
// Author: Chris Szalwinski, based on work by Heidar Davoudi
// Description:
// This file tests in_lab section of your workshop
//Name: Yuki Waka  Date: 07/20
//////////////////////////////////////////////////
#ifndef __IACCOUNT_H__
#define __IACCOUNT_H__
#include <iostream>

namespace sict {

	class iAccount {
	public:
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream&) const = 0;
		virtual ~iAccount() = default;
	};
	iAccount* CreateAccount(const char*, double);
}
#endif

