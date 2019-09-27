// Workshop 6 - Class with a Resource
// w6_in_lab.cpp
// OOP244
// Yuki Waka
// 2019/07/06

#ifndef __CONTACT_H__
#define __CONTACT_H__
#include <string>
using namespace std;


namespace sict {
	constexpr auto MAX_CHAR = 20;
	class Contact {

		char pName[MAX_CHAR];
		const long long *number;
		string countrycode[MAX_CHAR];
		string areacode[MAX_CHAR];
		string num1[MAX_CHAR];
		string num2[MAX_CHAR];
		int c_Number;
		string str;

	public:
		Contact();
		Contact(const char*, const long long*, int);
		~Contact();
		bool isEmpty() const;
		void display() const;
	};
}

#endif
