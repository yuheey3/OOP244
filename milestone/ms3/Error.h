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
/////////////////////////////////////////////////////////////////#
#ifndef _ERROR_H_
#define _ERROR_H_

namespace aid
{
	class Error {
	private:
		char* c_errorMessage;
	public:
		~Error();
		explicit Error(const char* errorMessage = nullptr);
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message() const;
	};
	std::ostream& operator<<(std::ostream& ostr, Error& ref);
}
#endif 
