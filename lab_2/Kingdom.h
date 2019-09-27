/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date May23
// Author Yuki Waka
// Description
//making namespace to combine various type of variable
//declear display
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//Yuki Waka  May 23
///////////////////////////////////////////////////////////
***********************************************************/

#ifndef _SICT_KINGDOM_H_
#define _SICT_KINGDOM_H_


namespace sict {
	// define the structure Kingdom in the sict namespace
	struct Kingdom {
		char m_name[33];  //declare appropriate variable
		int m_population;
	};
	

	void display(const Kingdom& i); //declear "display"

}
#endif