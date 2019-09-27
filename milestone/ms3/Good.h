// Final Project - Milestone 3 - Good Module
// --------------------------------------------------------------
// Name      Yuki Waka   Date     2019/07/29            Reason
/////////////////////////////////////////////////////////////////
#ifndef _GOOD_H_
#define _GOOD_H_
#include <iostream>
#include "Error.h"


namespace aid {

	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double tax_rate = 0.13;

	class Good {
	private:
		char good;
		char goodSku[max_sku_length + 1];
		char goodUnit[max_unit_length + 1];
		char * nameGood;
		int qty_OnHand;
		int qty;
		double beforeTax;
		bool taxable;
		Error errorstate;

	protected:
		void name(const char*);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double itemPrice() const;
		double itemCost() const;
		void message(const char*);
		bool isClear() const;

	public:

		Good(char prodType = 'N');
		Good(const char* p_goodSku, const char* p_nameGood, const char* p_goodUnit, int p_qty = 0, bool p_taxable = true, double p_price = 0.0, int q_hand = 0);
		Good(const Good& good);
		Good& operator= (const Good&);
		~Good();

		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);

		
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		bool operator>(const Good&) const;
		int operator+=(int);
	};

	std::ostream& operator<< (std::ostream&, const Good&);
	std::istream& operator>> (std::istream&, Good&);
	double operator +=(double&, const Good&);
}

#endif //_GOOD_H__