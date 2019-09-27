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
// Name    Yuki Waka       Date   July 11          Reason
/////////////////////////////////////////////////////////////////
#include<iostream>
#include<iomanip>
#include"Date.h"
using namespace std;


namespace aid {

	void Date::errCode(int errorCode) {

		m_errorState = errorCode;
	}

	int Date::mdays(int year, int mon) const
	{
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	Date::Date() {

		m_year = 0;
		m_month = 0;
		m_day = 0;
		m_comparator = 0;
		m_errorState = NO_ERROR;

	}
	bool Date::isValid(int year, int month, int day)
	{
		bool valid = false;

		m_errorState = YEAR_ERROR;

		if (year >= min_year && year <= max_year)
		{
			m_errorState = MON_ERROR;

			if (month >= 1 && month <= 12)
			{
				m_errorState = DAY_ERROR;

				if (day >= 1 && day <= 30)//(mdays(month, year)))
				{
					m_errorState = PAST_ERROR;

					if (min_date <= (year * 372 + month * 31 + day))
					{
						m_errorState = NO_ERROR;
						valid = true;
					}
				}
			}
		}
		return valid;

	}
	Date::Date(int year, int month, int day) {

		if (isValid(year, month, day)) {

			m_year = year;
			m_month = month;
			m_day = day;
			m_comparator = (year * 372 + month * 31 + day);
			m_errorState = NO_ERROR;
		}

		else
		{
			*this = Date();
		}
	}


	bool Date::operator==(const Date& rhs) const {
		return (((this->m_year == rhs.m_year) && (this->m_month == rhs.m_month) && (this->m_day == rhs.m_day)) ? true : false);
	}


	bool Date::operator!=(const Date& rhs) const
	{
		return !(*this == rhs);
	}



	bool Date::operator<(const Date& rhs) const {


		if (m_comparator != 0 || rhs.m_comparator != 0)
		{
			if (m_comparator < rhs.m_comparator)
			{
				return true;
			}
		}
		return true;
	}

	bool Date::operator>(const Date& rhs) const {
		if (m_comparator != 0 || rhs.m_comparator != 0)
		{
			if (m_comparator > rhs.m_comparator)
			{
				return true;
			}
		}
		return true;
	}

	bool Date::operator<=(const Date& rhs) const {
		if (m_comparator != 0 || rhs.m_comparator != 0)
		{
			if (m_comparator <= rhs.m_comparator)
			{
				return true;
			}
		}
		return true;
	}

	bool Date::operator>=(const Date& rhs) const {
		if (m_comparator != 0 || rhs.m_comparator != 0)
		{
			if (m_comparator >= rhs.m_comparator)
			{
				return true;
			}
		}
		return true;
	}

	int Date::errCode() const {

		return m_errorState;
	}

	bool Date::bad() const {

		return ((m_errorState != NO_ERROR) ? true : false);
	}



	std::istream& Date::read(std::istream& istr) 
   /*
		char mark = '/';
		int year;
		int month;
		int day;

		istr >> year >> mark >> month >> mark >> day;

		if (!(istr.fail()))
		{
			if (isValid(year, month, day))
			{
				m_year = year;
				m_month = month;
				m_day = day;
			}
			else
				istr.clear();
		}
		else
		{
			m_errorState = CIN_FAILED;
		}
		
	}
	*/
		{
			char symbolToIgnore;

			errCode(NO_ERROR);
			istr >> m_year >> symbolToIgnore >> m_month >> symbolToIgnore >> m_day;

			if (cin.fail() || istr.fail())
			{
				*this = Date();
				errCode(CIN_FAILED);
			}

			else if (!isValid(m_year, m_month, m_day))
			{
				istr.clear();
				return istr;
			}

			istr.clear();
			return istr;
		}

	std::ostream& Date::write(std::ostream& ostr) const {

		ostr << m_year << '/' << std::setfill('0') << std::setw(2) << m_month << '/'
			<< std::setfill('0') << std::setw(2) << m_day;
		return ostr;
	}

	std::ostream& operator << (std::ostream& ostr, Date& print) {
		print.write(ostr);
		return ostr;

	}
	std::istream& operator >> (std::istream& istr, Date& rea) {
		rea.read(istr);
		return istr;
	}
}