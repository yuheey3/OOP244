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
	if (sin <= max_sin && sin >= min_sin) {
		strncpy(theFamilyName, familyName, max_name_length);
		strncpy(theGivenName, givenName, max_name_length);
		theSin = sin;
	}
	else {
		*theFamilyName = '\0';
		*theGivenName = '\0';
		sin = 0;
	}
}


bool CRA_Account::isEmpty() const {
	return (*theFamilyName == '\0' ? true : false);
}



void CRA_Account::display() const {
	if (!isEmpty()) {
		cout << "Family Name: " << theFamilyName << endl;
		cout << "Given Name : " << theGivenName << endl;
		cout << "CRA Account: " << theSin << endl;
	}
	else
		cout << "Account object is empty!" << endl;
}