/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date May 23
// Author Yuki Waka
// Description
// Difinition of display
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//Yuki Waka  May 23 
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
}