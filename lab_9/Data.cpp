// Workshop 9 - Function Templates
// File: w9_in_lab.cpp
// Version: 2.0
// Date: 2018/11/02
// Author: Chris Szalwinski, based on work by Hasan Murtaza
// Description:
// This file implements the application
//Name: Yuki Waka 
//Student #: 141082180
//////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Data.h"

using namespace std;

namespace sict {
	
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"

		cout.precision(2);
		cout.setf(ios::fixed);
		cout << "Population change from 2000 to 2004 is " <<
			static_cast<double>(population[n - 1] - population[0]) / 1000000<< " million" << endl;
	
	

		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
	cout << "Violent Crime trend is ";

	if(violentCrimeRate[n-1] < violentCrimeRate[0])
	{
		cout << "down" << endl;
	}
	else
	{
		cout << "up" << endl;
	}



		// Q3 print the GTA number accurate to 0 decimal places

	cout << "There are " << average(grandTheftAuto, n) / 1000000
			<< " million Grand Theft Auto incidents on average a year" << endl;


		// Q4. Print the min and max violentCrime rates

	cout << "The Minimum Violent Crime rate was " <<
			static_cast <int>(min(violentCrimeRate, n)) << endl;
	cout << "The Maximum Violent Crime rate was " <<
			static_cast<int>(max(violentCrimeRate, n)) << endl;

	}
}