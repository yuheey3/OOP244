// Workshop 5: operator overloading
// File: w5_at_home.cpp
// Version: 2.1
// Date: 2019/06/14
// Author: Yuki Waka
// Description:
// This file tests in-lab section of your workshop
/////////////////////////////////////////////
// TODO: header file guard
#ifndef __FRACTION_H__
#define __FRACTION_H__

// TODO: create namespace
namespace sict {
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		int numerator;
		int denominator;
		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int, int);
		bool isEmpty() const;
		void display() const;
		// TODO: declare the + operator overload
		Fraction operator+ (const Fraction& rhs) const;
		Fraction operator* (const Fraction& rhs) const;
		bool operator== (const Fraction& rhs) const;
		bool operator!= (const Fraction& rhs) const;
		Fraction operator+= (const Fraction& rhs);

	};
}
#endif // !__FRACTION_H__