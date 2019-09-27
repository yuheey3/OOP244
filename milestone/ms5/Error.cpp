// --------------------------------------------------------------
// Name    Yuki Waka       Date   2019/08/08   student#: 141082180   
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
#include "Error.h"

namespace aid
{
	Error::Error(const char* errorMessage)
	{
		int count = 0;

		if (errorMessage == nullptr)
		{
			errM = nullptr;
		}

		else
		{
			for (int i = 0; errorMessage[i] != '\0'; i++)
			{
				count++;
			}

			errM = new char[count + 1];

			strncpy(errM, errorMessage, count);
			errM[count] = '\0';
		}
	}

	Error::~Error()
	{
		delete[] errM;
	}

	void Error::clear()
	{
		delete[] errM;
		errM = nullptr;
	}

	bool Error::isClear() const
	{
		bool clear = false;

		if (errM == nullptr)
		{
			clear = true;
		}

		return clear;
	}

	void Error::message(const char* str)
	{
		clear();

		int count = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			count++;
		}

		errM = new char[count + 1];
		strncpy(errM, str, count);
		errM[count] = '\0';

		return;
	}

	const char* Error::message() const
	{
		return errM;
	}

	std::ostream& operator << (std::ostream& os, const Error& msgObj)
	{
		if (!(msgObj.isClear()))
		{
			os << msgObj.message();
		}

		return os;
	}

}