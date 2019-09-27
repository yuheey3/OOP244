
/***********************************************************
// Workshop 2: Dynamic Memory
// File w2_in_lab.cpp
// Version 2.0
// Date May 23
// Author Yuki Waka
// Description
// To get input from user about Kingdom information
//It stored and show info.
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//Yuki Waka    May 23
///////////////////////////////////////////////////////////
***********************************************************/

#include <iostream>
#include "Kingdom.h"
#include "Kingdom.h" // intentional

using namespace std;
using namespace sict;

void read(sict::Kingdom&);

int main() {
	int count = 0; // the number of kingdoms in the array

	Kingdom* pKingdom = nullptr;   //initialize pKingdom to make null.
	cout << "==========" << endl
		<< "Input data" << endl
		<< "==========" << endl
		<< "Enter the number of Kingdoms: ";
	cin >> count;
	cin.ignore();

	if (count < 1) return 1;

	//  allocate dynamic memory here for the pKingdom pointer
	pKingdom = new Kingdom[count];

	for (int i = 0; i < count; ++i) {
		cout << "Kingdom #" << i + 1 << ": " << endl;
		//  add code to accept user input for Kingdom i
		read(pKingdom[i]);
	}
	cout << "==========" << endl << endl;

	
	cout << "------------------------------" << endl
		<< "The 2nd kingdom entered is" << endl
		<< "------------------------------" << endl;
	sict::display(pKingdom[1]);
	cout << "------------------------------" << endl << endl;

	//  deallocate the dynamic memory 
	delete[] pKingdom;
	
	return 0;
}


//definition of read
void read(sict::Kingdom& kingdom) {

	cout << "Enter the name of the Kingdom: ";
	cin.get(kingdom.m_name, 32, '\n');
	cin.ignore(2000, '\n');
	cout << "Enter the number of people living in " << kingdom.m_name << ": ";
	cin >> kingdom.m_population;
	cin.ignore(2000, '\n');
}
