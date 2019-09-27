// Workshop 7 - Derived Classes
// File w7_at_home.cpp
// Version 2.0
// Date 2019/07/15
// Author       Yuki Waka
// Student number: 141082180
// Description
//
/////////////////////////////////////////////////////
#ifndef __SUPERHERO_H__
#define __SUPERHERO_H__
#include "Hero.h"
using namespace std;

namespace sict {

	class SuperHero : public Hero {
		int bonus;
		int defends;
	public:
		SuperHero();
		SuperHero(const char*, int, int, int, int);
		int attackStrength()const;
		int defend()const;
	};

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}
#endif