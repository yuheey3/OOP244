/***********************************************************
// Workshop 2: Dynamic Memory
// File w2_at_home.cpp
// Version 2.0
// Date May 24
// Author Yuki Waka
// Description
// Practice for allocate and deallocate dynamic memory
//for an array of element
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//Yuki Waka   May 24
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

  // declare the pKingdom pointer 
	Kingdom* pKingdom = nullptr;
	cout << "==========\n"
		<< "Input data\n"
		<< "==========\n"
		<< "Enter the number of Kingdoms: ";
	cin >> count;
	cin.ignore();

	if (count < 1) return 1;


	pKingdom = new Kingdom[count];

	for (int i = 0; i < count; ++i) {
		cout << "Kingdom #" << i + 1 << ": " << endl;
		read(pKingdom[i]);
	}
	cout << "==========" << endl << endl;

	// testing that "display(...)" works
	cout << "------------------------------" << endl
		<< "The 1st Kingdom entered is" << endl
		<< "------------------------------" << endl;
	display(pKingdom[0]);
	cout << "------------------------------" << endl << endl;

	// expand the array of Kingdoms by 1 element

		// allocate dynamic memory for count + 1 Kingdoms
	Kingdom* pKing2 = nullptr;
	pKing2 = new Kingdom[count + 1];
	// copy elements from original array into this newly allocated array
	for (int i = 0; i < count; i++) {
		pKing2[i] = pKingdom[i];
	}
	//deallocate the dynamic memory for the original array
	delete[] pKingdom;
	pKingdom = nullptr;
	//copy the address of the newly allocated array into pKingdom pointer
	pKingdom = pKing2;
	// add the new Kingdom
	cout << "==========\n"
		<< "Input data\n"
		<< "==========\n"
		<< "Kingdom #" << count + 1 << ": " << endl;
	// accept input for the new element in the array
	read(pKing2[count]);
	count++;
	cout << "==========\n" << endl;




	// testing that the overload of "display(...)" works
	display(pKingdom, count);

	delete[] pKing2;
	pKing2 = nullptr;


	return 0;
}

// read accepts data for a Kingdom from standard input
//
void read(Kingdom& kingdom) {
	cout << "Enter the name of the Kingdom: ";
	cin.get(kingdom.m_name, 32, '\n');
	cin.ignore(2000, '\n');
	cout << "Enter the number of people living in " << kingdom.m_name << ": ";
	cin >> kingdom.m_population;
	cin.ignore(2000, '\n');
}