/*********************************
Name: Yuki Waka
Student Number: 141082180
Course: OOP SCC
Date:10June
**********************************/
// TODO: add file header comments here
#include <iostream>
#include <cstring>
// TODO: add your headers here
#include "Passenger.h"

#define warning (disable:4996)
// TODO: continue your namespace here
using namespace sict;
using namespace std;
	// TODO: implement the default constructor here
Passenger::Passenger() {
	*thePassenger = '\0';
	*theDestination = '\0';
		yearDepart = 0;
		monthDepart = 0;
		dayDepart = 0;
}
	// TODO: implement the constructor with 2 parameters here
Passenger::Passenger(const char* name, const char* dest) {
	if (name != '\0' || name != nullptr) {
		for (int i = 0; i < 19; i++)
			thePassenger[i] = name[i];
		thePassenger[18] = '\0';
		if (dest != '\0' || dest != nullptr) {
			for (int i = 0; i < 19; i++) {
				theDestination[i] = dest[i];
			}
		}
		else
			theDestination[0] = '\0';
	}
	else {
		thePassenger[0] = '\0';
		if (dest != '\0' || dest != nullptr) {
			for (int i = 0; i < 19; i++)
				theDestination[i] = dest[i];
		}
		else
			theDestination[0] = '\0';
	}
	yearDepart = 2019;
	monthDepart = 10;
	dayDepart = 01;
}

Passenger::Passenger(const char* name, const char* dest, int year, int month, int day)
{
	if (name != '\0' || name != nullptr) {
		for (int i = 0; i < 19; i++)
			thePassenger[i] = name[i];
		thePassenger[18] = '\0';
		if (dest != '\0' || dest != nullptr) {
			for (int i = 0; i < 19; i++)
				theDestination[i] = dest[i];
		}
		else

			theDestination[0] = '\0';
	}
	else {
		thePassenger[0] = '\0';
		if (dest != '\0' || dest != nullptr) {
			for (int i = 0; i < 19; i++)
				theDestination[i] = dest[i];
		}
		else
			theDestination[0] = '\0';
	}
	

	if (year > 2018 && year < 2022) {
		yearDepart = year;
			if (month > 0 && month < 13)
				monthDepart = month;
			else 
				monthDepart = 0;
			if (day > 0 && day < 32)
				dayDepart = day;
			else
				dayDepart = 0;
	}
	else
	{
		yearDepart = 0;
		monthDepart = 0;
		dayDepart = 0;
	}
}

		


	// TODO: implement isEmpty query here
bool Passenger::isEmpty() const {
	return(thePassenger[0] == '\0' ||  theDestination[0] == '\0' ? true : false);
}
	
// TODO: implement display query here
void Passenger::display()const {
	if (thePassenger[0] == '\0' || theDestination[0] == '\0' || yearDepart == 0 || monthDepart == 0 || dayDepart == 0)
		cout << "No passenger!" << endl;
	else
		if (dayDepart > 0 && dayDepart < 10) {
			cout << thePassenger << " - " << theDestination << " on "
				<< yearDepart << "/" << monthDepart << "/";
			cout.setf(ios::fixed);
			cout.width(2);
			cout.fill('0');
			cout << dayDepart << endl;
		}
		else
			cout << thePassenger << " - " << theDestination << " on "
			<< yearDepart << "/" << monthDepart << "/" << dayDepart << endl;
		
}

const char* Passenger::name() const
{
	if (thePassenger == '\0')
		return "";
	else
		return thePassenger;
}

bool Passenger::canTravelWith(const Passenger& des) const{

	if(strcmp(theDestination, des.theDestination) == 0)
		return true;
	return false;
}