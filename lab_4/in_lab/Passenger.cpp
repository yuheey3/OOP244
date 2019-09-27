/**********************
Name : Yuki Waka
Date   : 06 06 2019
S #       : 141082180
Section: SCC 
**********************/
// TODO: add file header comments here
#include <iostream>
#include <string.h>
// TODO: add your headers here
#include "Passenger.h"

#define warning (disable:4996)
// TODO: continue your namespace here
using namespace std;
using namespace sict;
	// TODO: implement the default constructor here
Passenger::Passenger() {
	*thePassenger = '\0';
	*theDestination = '\0';
}
	// TODO: implement the constructor with 2 parameters here
Passenger::Passenger(const char* name, const char* dest) {
	/*
	if (strnlen_s(name, 100) > sizeof(thePassenger)) {
		int i = 0;
		for (; i < sizeof(thePassenger); i++)
			thePassenger[i] = name[i];
		
		for (i = 0; i < sizeof(theDestination); i++)
			theDestination[i] = dest[i];
			
		thePassenger[18] = '\0';
		theDestination[18] = '\0';
	}
	
	else
	{
		if (name == '\0')
			*thePassenger = '\0';
		else
			strcpy_s(thePassenger, name);

		if (dest == '\0')
			*theDestination = '\0';
		else
			strcpy_s(theDestination, dest);
	}
	*/

	if (name != '\0') {
		for (int i = 0; i < 19; i++)
			thePassenger[i] = name[i];
		thePassenger[18] = '\0';
		if (dest != '\0') {
			for (int i = 0; i < 19; i++)
				theDestination[i] = dest[i];
			
		}
		else
			theDestination[0] = '\0';
	}
	else {
		thePassenger[0] = '\0';
		if (dest != '\0') {
			for (int i = 0; i < 19; i++)
				theDestination[i] = dest[i];
		}
		else
			theDestination[0] = '\0';
	}
}
	// TODO: implement isEmpty query here
bool Passenger::isEmpty() const {
	return (thePassenger[0] == '\0' || theDestination[0] == '\0' ? true : false);
}
	// TODO: implement display query here

void Passenger::display() const {
	if (thePassenger[0] == '\0')
		cout << "No passenger!" << endl;
	else
		cout << thePassenger << " - " << theDestination << endl;
}