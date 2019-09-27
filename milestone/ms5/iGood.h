// --------------------------------------------------------------
// Name    Yuki Waka       Date   2019/08/08   student#: 141082180   
/////////////////////////////////////////////////////////////////
#ifndef _IGOOD_H
#define _IGOOD_H

#include <iostream>
#include <fstream>

namespace aid
{
	class iGood
	{
	public:
		virtual ~iGood() {};
		virtual std::fstream& store(std::fstream& file, bool newLine = true) const = 0;
		virtual std::fstream& load(std::fstream& file) = 0;
		virtual std::ostream& write(std::ostream& os, bool linear) const = 0;
		virtual std::istream& read(std::istream& is) = 0;
		virtual bool operator==(const char* str) const = 0;
		virtual double total_cost() const = 0;
		virtual const char* name() const = 0;
		virtual void quantity(int) = 0;
		virtual int qtyNeeded() const = 0;
		virtual int quantity() const = 0;
		virtual int operator+=(int) = 0;
		virtual bool operator>(const iGood&) const = 0;
	};

	std::ostream& operator<<(std::ostream& os, const iGood& other);
	std::istream& operator>>(std::istream& is, iGood& other);
	double operator+=(double& total, const iGood& other);
	iGood* CreateProduct(char tag);
	//iGood* CreatePerishable();
}

#endif 