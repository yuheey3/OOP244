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
#include "Hero.h"
#define _CRT_SECURE_NO_WARNINGS


using namespace std;

namespace sict {

	Hero::Hero() {
		name[0] = '\0';
		health = 0;
		strength = 0;
	}

	Hero::Hero(const char* hName, int hHealth, int hStrength) {
		if (hName[0] != '\0' && hHealth > 0 && hStrength > 0) {
			strncpy(name, hName, 40);

			health = hHealth;
			strength = hStrength;
		}
		else {
			name[0] = '\0';
			health = 0;
			strength = 0;
		}

	}
	void Hero::operator-=(int attack) {
		if (attack > 0 && health > 0) {
			health -= attack;

			if (health < 0) {
				health = 0;
			}
		}
	}

	bool Hero::isAlive() const {
		return ((health > 0) ? true : false);
	}

	int Hero::attackStrength()const {
		return ((this->strength != 0) ? this->strength : 0);

	}

	std::ostream& operator<<(std::ostream& os, const Hero& hero) {

		if (hero.name == nullptr)
			os << "no hero";

		else
			os << hero.name;
		return os;


	}

	const Hero& operator*(const Hero& first, const Hero& second) {



		Hero copy_First;
		Hero copy_Second;
		copy_First = first;
		copy_Second = second;
		Hero winner;
		int round = 0;


		for (int i = 0; i < MAX_ROUNDS &&
			(copy_First.isAlive() && copy_Second.isAlive()); i++) {
				{
					copy_First -= copy_Second.attackStrength();
					copy_Second -= copy_First.attackStrength();
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


		cout << "Ancient Battle! " << first << " vs " << second << " : Winner is "
			<< winner << " in " << round << " rounds." << endl;

		return copy_First.isAlive() ? first : second;


	}
}


	