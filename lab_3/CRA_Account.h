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

#ifndef __CRA_ACCOUNT_H__
#define __CRA_ACCOUNT_H__

#include <iostream>
using namespace std;

namespace sict {
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;

	class CRA_Account {
	private:
		char theFamilyName[max_name_length + 1];
		char theGivenName[max_name_length + 1];
		int theSin;

	public:
		void set(const char* familyName, const char* givenName, int sin);

		bool isEmpty() const;
		void display() const;
	};

}
#endif // !__CRA_ACCOUNT_H__
