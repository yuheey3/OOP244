// --------------------------------------------------------------
// Name    Yuki Waka       Date   2019/08/08   student#: 141082180   
/////////////////////////////////////////////////////////////////
#ifndef _GOOD_H_
#define _GOOD_H_

#include <iostream>
#include "Error.h"
#include "iGood.h"


namespace aid {
	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double taxRate = 0.13;

	class Good : public iGood {
		char goodType;
		char goodSku[max_sku_length + 1];
		char goodUnit[max_unit_length + 1];
		char * goodName;
		int qtyOnHand;
		int qtyReq;
		double priceBefore;
		bool taxable;

	protected:
		void name(const char*);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double price() const;
		double cost() const;
		void message(const char*);
		bool isClear() const;
		Error er;

	public:

		Good(char goodType = 'N');
		Good(const char* goodSku, const char* goodName, const char* goodUnit, int qtyOnHand = 0, bool tax = true, double prodPrice = 0.0, int qtyNeed = 0);
		Good(const Good& p_good);
		~Good();

		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);

		Good& operator= (const Good&);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		int operator+=(int);

		bool operator > (const iGood&) const;
	};
	std::ostream& operator<< (std::ostream&, const iGood&);
	std::istream& operator>> (std::istream&, iGood&);
	double operator +=(double&, const iGood&);
}
#endif