// Workshop 7 - Derived Classes
// File w7_at_home.cpp
// Version 2.0
// Date 2019/07/15
// Author       Yuki Waka
// Student number: 141082180
// Description
//
/////////////////////////////////////////////////////
#include<iostream>
#include<cstring>
#include<string>
#include "SuperHero.h"
#define _CRT_SECURE_NO_WARNINGS


using namespace std;

namespace sict {

SuperHero::SuperHero() {
	bonus = 0;
	defends = 0;
}

SuperHero::SuperHero(const char* Name, int Health, int Strength, int Bonus, int Defends) : Hero (Name, Health, Strength) {

	if (Name[0] != '\0' && Health > 0 && Strength > 0 && Bonus > 0 && Defends > 0) {
		
		bonus = Bonus;
		defends = Defends;
	}
	else {
		bonus = 0;
		defends = 0;
	}

}

int SuperHero::attackStrength()const {

	return (Hero::attackStrength() + bonus);
}

int SuperHero::defend()const {

	return ((this->defends != 0) ? this->defends : 0);
}

const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {

	SuperHero copy_First;
	SuperHero copy_Second;
	copy_First = first;
	copy_Second = second;
	SuperHero winner;
	int round = 0;


	for (int i = 0; i < MAX_ROUNDS &&
		(copy_First.isAlive() && copy_Second.isAlive()); i++) {
			{
				copy_First -= (copy_Second.attackStrength() - copy_First.defend());
				copy_Second -= (copy_First.attackStrength() - copy_Second.defend());
				round++;
			}

	}

	if (!copy_First.isAlive() && !copy_Second.isAlive())
	{
		winner = copy_First;

	}
	else if (!copy_First.isAlive() && copy_Second.isAlive())
	{
		winner = copy_Second;
	}

	else if (!copy_Second.isAlive() && copy_First.isAlive())
	{
		winner = copy_First;
	}
	else
		return first;


	cout << "Super Fight! " << first << " vs " << second << " : Winner is "
		<< winner << " in " << round << " rounds." << endl;

	return copy_First.isAlive() ? first : second;


	}


}



