/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date May 24
// Author Yuki Waka
// Description
// Difinition of display
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//Yuki Waka  May 24
///////////////////////////////////////////////////////////
***********************************************************/


#include <iostream>
#include "Kingdom.h"

using namespace std;

//definition of display
namespace sict {

	void display(const Kingdom& i) {

		cout << i.m_name << ", " << "population " << i.m_population << endl;

	}
	void display(const Kingdom king[], int size) {

		int total = 0;//Initialize for total

		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;
		for (int i = size - 1; i >= 0; i--) { //reverse order
			cout << i + 1 << ". " << king[i].m_name << ", population " << king[i].m_population << endl;
		}
		for (int i = 0; i < size; i++) {
			total += king[i].m_population; //using for loop, add total population.
		}
		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << total << endl;
		cout << "------------------------------" << endl;

	}
}




