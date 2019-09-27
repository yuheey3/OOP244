// Workshop 7 - Derived Classes
// File w7_at_home.cpp
// Version 2.0
// Date 2019/07/15
// Author       Yuki Waka
// Student number: 141082180
// Description
//
/////////////////////////////////////////////////////
#ifndef __HERO_H__
#define __HERO_H__
#include<iostream>


namespace sict {
	const int MAX_ROUNDS = 100;

	class Hero {
		char name[41];
		int health;
		int strength;
	public:
		Hero();
		Hero(const char*, int, int);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength()const;

		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};

	const Hero& operator*(const Hero& first, const Hero& second);

}
#endif 















