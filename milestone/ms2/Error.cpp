// Final Project Milestone 2 - Error Class
// Version 3.7
// ms2.cpp
// Date	2019-06-22
// Author	Chris Szalwinski, Fardad Soleimanloo, Cornel
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
// Revision History
// --------------------------------------------------------------
// Name       Yuki Waka        Date   2019/07/18          Reason
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
#include "Error.h"
#define CRT_SECURE_NO_WARNINGS
using namespace std;

namespace aid
{
	Error::~Error()
	{
		delete[] c_errorMessage;
		c_errorMessage = nullptr;
	}

	Error::Error(const char* errorMessage){
		int count = 0;

		if (errorMessage == nullptr || 
			errorMessage[0] == '\0')
		{
			c_errorMessage = nullptr;
		}
		else
		{
			for (int i = 0; errorMessage[i] != '\0'; i++)
			{
				count++;
			}
			c_errorMessage = new char[count + 1];
			strncpy(c_errorMessage, errorMessage, count);
			c_errorMessage[count] = '\0';
		}
	}

	void Error::clear()
	{
		delete[] c_errorMessage;
		c_errorMessage = nullptr;
	}

	bool Error::isClear() const
	{
		return (c_errorMessage == nullptr) ? true : false;
	}

	void Error::message(const char* str)
	{
		clear();

		int count = 0;

		if (str == nullptr || str[0] == '\0') {
			this->c_errorMessage = nullptr;
		}
		else {

			for (int i = 0; str[i] != '\0'; i++)
			{
				count++;
			}
			c_errorMessage = new char[count + 1];
			strncpy(c_errorMessage, str, count);
			c_errorMessage[count] = '\0';
		}
		return;
	}

	const char* Error::message() const{
	if (this->c_errorMessage != '\0' && this->c_errorMessage != nullptr) {

		return this->c_errorMessage;
	}
	else 
		return nullptr;
	} 

	std::ostream& operator <<(std::ostream& ostr, Error& ref) {
		if (!ref.isClear())
		{
			ostr << ref.message();
		}
		return ostr;
	}
}