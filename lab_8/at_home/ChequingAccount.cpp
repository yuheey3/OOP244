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
#include "iAccount.h"
#include "ChequingAccount.h"

namespace sict{
	
	ChequingAccount::ChequingAccount(double iniBalance, double transaction, double monthend) {

		currBalance = iniBalance;

		if (transaction > 0)
		{
			tranSaction = transaction;
		}
		else
		{
			tranSaction = 0.0;
		}

		if (monthend > 0)
		{
			monthFee = monthend;
		}
		else
		{
			monthFee = 0.0;
		}
	}

	bool ChequingAccount::credit(double credit) {
		
			bool check = false;
			currBalance += credit;
			if (currBalance > 0) {
				currBalance -= tranSaction;
			}
			if (currBalance > 0) {
				check = true;
			}
			return check;
	}

	bool ChequingAccount::debit(double debit) {
		
		bool check = false;
		currBalance -= debit;
		if (currBalance > 0) {
			currBalance -= tranSaction;
		}
		if (currBalance > 0) {
			check = true;
		}
		return check;
}

	void ChequingAccount::monthEnd() {
		currBalance -= monthFee;
	}

	void ChequingAccount::display(std::ostream& os) const {

		os << "Account type: Chequing" << std::endl;
		os.unsetf(std::ios::floatfield);
		os.precision(2);
		os.setf(std::ios::fixed, std::ios::floatfield);
		os << "Balance: $" << balance() << std::endl;
		os << "Per Transaction Fee: " << tranSaction << std::endl;
		os << "Monthly Fee: " << monthFee << std::endl;
	}
}