// Workshop 5: operator overloading
// File: w5_at_home.cpp
// Version: 2.1
// Date: 2019/06/14
// Author: Yuki Waka
// Description:
// This file tests in-lab section of your workshop
/////////////////////////////////////////////

// TODO: insert header files
#include "Fraction.h"
#include <iostream>
// TODO: continue the namespace
using namespace sict;
using namespace std;

// TODO: implement the default constructor
Fraction::Fraction() {
	this->numerator = this->denominator = 0;
};
// TODO: implement the two-argument constructor
Fraction::Fraction(int numerator, int denominator) {
	if (numerator < 0 || denominator <= 0)
		this->numerator = this->denominator = 0;
	else {
		this->numerator = numerator;
		this->denominator = denominator;
	}
	Fraction::reduce();
}
// TODO: implement the max query
int Fraction::max() const {
	return (this->numerator > this->denominator ? this->numerator : this->denominator);
}
// TODO: implement the min query
int Fraction::min() const {
	return (this->numerator < this->denominator ? this->numerator : this->denominator);
}
// gcd returns the greatest common divisor of num and denom
//
int Fraction::gcd() const {
	int mn = min();  // min of numerator and denominator
	int mx = max();  // max of numerator and denominator
	int g_c_d = 1;
	bool found = false;

	for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
		if (mx % x == 0 && mn % x == 0) {
			found = true;
			g_c_d = x;
		}
	}
	return g_c_d;
}

// TODO: implement the reduce modifier
void Fraction::reduce() {
	int temp = gcd();
	this->denominator /= temp;
	this->numerator /= temp;
}
// TODO: implement the display query
void Fraction::display() const {
	if (this->denominator == 0 || this->numerator == 0)
		cout << "no fraction stored";
	else if (this->numerator % this->denominator == 0)
		cout << this->numerator / this->denominator;
	else
		cout << this->numerator << "/" << this->denominator;

}
// TODO: implement the isEmpty query
bool Fraction::isEmpty() const {
	return ((this->denominator == 0 || this->denominator == 0) ? true : false);
}
// TODO: implement the + operator
Fraction Fraction::operator+ (const Fraction& rhs) const {
	Fraction newFrac;
	if (isEmpty() && rhs.isEmpty()) {
		cout << "no fraction stored" << endl;
		
	}
	else {
		Fraction newFrac;
		newFrac.denominator = this->denominator * rhs.denominator;
		newFrac.numerator = this->numerator * rhs.denominator + this->denominator * rhs.numerator;
		return newFrac;
	}
	return newFrac;
}
Fraction Fraction::operator* (const Fraction& rhs) const {
	Fraction newFrac;
	if (isEmpty() && rhs.isEmpty()) {
		cout << "no fraction stored" << endl;
	}
	else {
		Fraction newFrac;
		newFrac.denominator = this->denominator * rhs.denominator;
		newFrac.numerator = this->numerator * rhs.numerator;
		return newFrac;
	}
	return newFrac;
}
bool Fraction::operator== (const Fraction& rhs) const
{
	
		return (((!isEmpty() && !rhs.isEmpty()) && (this->denominator == rhs.denominator && this->numerator == rhs.numerator)) ? true : false);
	
}

bool Fraction::operator!= (const Fraction& rhs) const 
{
	return (((!isEmpty() && !rhs.isEmpty()) && (this->denominator != rhs.denominator || this->numerator != rhs.numerator))? true : false);
}
Fraction Fraction::operator+= (const Fraction& rhs) {

	Fraction newFrac;
	if (isEmpty() && rhs.isEmpty()) {
		Fraction();
		return *this;
	}
	else {
		Fraction newFrac;
		newFrac.denominator = this->denominator * rhs.denominator;
		newFrac.numerator = this->numerator * rhs.denominator + this->denominator * rhs.numerator;
		this->denominator = newFrac.denominator;
		this->numerator = newFrac.numerator;
		return *this;
	}
	return *this;
}



