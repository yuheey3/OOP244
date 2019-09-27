/**********************************************************
// Workshop 3: Classes and Privacy
// w3_at_home.cpp
// Version 3.0
// 2019/05/19
// Cornel
// Description
// This workshop demonstrates classes in C++ and
// how member variables are defined privately, but
// accessed through public member functions
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		          Reason
// Yuki Waka    2019/05/30            allow longer names
///////////////////////////////////////////////////////////
**********************************************************/
#include <iostream>
#include "CRA_Account.h"
#include <cstring>
using namespace std;
using namespace sict;

void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
	int sinCheck[9];
	int temp = sin;
	for (int i = 8; i >= 0; i--) {
		sinCheck[i] = sin % 10;
		sin = sin / 10;
	}

	int even = 0;
	for (int i = 1; i < 9; i += 2)
		even += sinCheck[i];

	even *= 2;

	int odd = sinCheck[0] + sinCheck[2] + sinCheck[4] + sinCheck[6];
	int total = (int)(even / 2) + odd;

	if (temp <= max_sin && temp >= min_sin && familyName != NULL && givenName != NULL && ((((total / 10) + 1) * 10 - total) == sinCheck[8])) {
		strncpy(theFamilyName, familyName, max_name_length);
		strncpy(theGivenName, givenName, max_name_length);
		theSin = sin;
		num_Years = 0;
	}
	else {
		*theFamilyName = '\0';
		*theGivenName = '\0';
		sin = 0;
	}
	theSin = temp;
}


bool CRA_Account::isEmpty() const {
	return (*theFamilyName == '\0' ? true : false || *theGivenName == '\0' ? true : false);
}



void CRA_Account::display() const {
	if (!isEmpty()) {
		cout << "Family Name: " << theFamilyName << endl;
		cout << "Given Name : " << theGivenName << endl;
		cout << "CRA Account: " << theSin << endl;

		for (int i = 0; i < num_Years; i++) {
			if (balance_Ref[i] > 2) {
				cout << "Year (" << taxReturnYear[i] << ")" << " balance owing: " << balance_Ref[i] << endl;
			}
			else if (refund_Due[i] > 2) {
				cout.setf(ios::fixed);
				cout.precision(2);
				cout << "Year (" << taxReturnYear[i] << ")" << " refund due: " << refund_Due[i] << endl;
			}
			else if (balance_Ref[i] != 0 || refund_Due[i] != 0) {
				cout << "Year (" << taxReturnYear[i] << ")" << " No balance owing or refund due!" << endl;
			}
			else
				cout << "Account object is empty!" << endl;
		}
	}
}

void CRA_Account::set(int year, double balance) {
	if (year != 0 && balance != 0 && num_Years < max_yrs) {
		int i = 0;
		i = num_Years;
		taxReturnYear[i] = year;
		if (balance > 0) {
			balance_Ref[i] = balance;
		}
		else {
			refund_Due[i] = -balance;
		}
		++num_Years;
		year = 0;
		balance = 0;
	}
	else {
		return;
	}
}