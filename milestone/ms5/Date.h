// Final Project Milestone 1 - Date Module Tester
// Version 3.7.0
// ms1_prof.cpp
// Date 2019-06-22
// Author       Chris Szalwinski, Fardad Soleimanloo, Cornel
// Description
// This program test the student implementation of the Date class
// for submission.
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
//
// Revision History
// --------------------------------------------------------------
// Name    Yuki Waka       Date   August 08         Reason
/////////////////////////////////////////////////////////////////
#ifndef __DATE_H__
#define __DATE_H__

namespace aid {

	const int min_year = 2018;
	const int max_year = 2038;
	const int min_date = 751098;

	class Date {

#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4
#define PAST_ERROR 5

	private:
		int m_year;
		int m_month;
		int m_day;
		int m_comparator;
		int m_errorState;

		void errCode(int errorCode);
		int mdays(int, int) const;


	public:
		Date();
		bool isValid(int, int, int);
		Date(int, int, int);
		int errCode() const;
		bool bad() const;

		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;


	};
	std::ostream& operator << (std::ostream& ostr, Date&);
	std::istream& operator >> (std::istream& istr, Date&);

}
#endif

