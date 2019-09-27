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
// Yuki Waka    2019/06/03            allow longer names
///////////////////////////////////////////////////////////
**********************************************************/

#ifndef __CRA_ACCOUNT_H__
#define __CRA_ACCOUNT_H__

#include <iostream>
using namespace std;

namespace sict {
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;

	class CRA_Account {
	private:
		char theFamilyName[max_name_length + 1];
		char theGivenName[max_name_length + 1];
		int theSin;
		int taxReturnYear[max_yrs];
		double balance_Ref[max_yrs];
		double refund_Due[max_yrs];
		int num_Years = 0;

	public:
		void set(const char* familyName, const char* givenName, int sin);

		bool isEmpty() const;
		void display() const;
		void set(int year, double balance);
	};

}
#endif // !__CRA_ACCOUNT_H__