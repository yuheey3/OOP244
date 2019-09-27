// Final Project - Milestone 3 - Good Module
// --------------------------------------------------------------
// Name      Yuki Waka   Date     2019/07/29            Reason
/////////////////////////////////////////////////////////////////
#include <cstring>
#include <string>
#include <fstream>
#include <iomanip>
#include "Good.h"
#define CRT_SECURE_NO_WARNINGS

using std::cin;
using std::cout;

namespace aid 
{

	void Good::name(const char* p_nameGood)
	{
		if (p_nameGood != nullptr)
		{
			int i;

			for (i = 0; p_nameGood[i] != '\0' || i <= max_name_length; i++);

			nameGood = new char[i + 1];

			strncpy(nameGood, p_nameGood, i);
			nameGood[i] = '\0';
		}

		else
		{
			delete[] nameGood;
		}

		return;
	}

	const char* Good::name() const
	{
		return nameGood;
	}

	const char* Good::sku() const
	{
		return goodSku;
	}

	const char* Good::unit() const
	{
		return goodUnit;
	}

	bool Good::taxed() const
	{
		return taxable;
	}

	double Good::itemPrice() const
	{
		return beforeTax;
	}

	double Good::itemCost() const
	{
		double cost;

		if (taxable)
		{
			cost = beforeTax * (1 + tax_rate);
		}

		else
		{
			cost = beforeTax;
		}


		return cost;
	}

	void Good::message(const char* err)
	{
		errorstate.message(err);

		return;
	}

	bool Good::isClear() const
	{
		bool clear = false;

		clear = errorstate.isClear();

		return clear;
	}

	Good::Good(char p_good)
	{
		good = p_good;
		goodSku[0] = '\0';
		goodUnit[0] = '\0';
		nameGood = nullptr;
		qty_OnHand = 0;
		qty = 0;
		beforeTax = 0.0;
		taxable = false;

	}

	Good::Good(const char* p_goodSku, const char* p_nameGood, const char* p_goodUnit, int p_qty, bool p_taxable, double p_price, int p_hand)
	{
		name(p_nameGood);

		strncpy(goodSku, p_goodSku, max_sku_length);
		goodSku[max_sku_length] = '\0';

		strncpy(goodUnit, p_goodUnit, max_unit_length);
		goodUnit[max_unit_length] = '\0';

		qty_OnHand = p_qty;
		taxable = p_taxable;
		beforeTax = p_price;
		qty = p_hand;
	}

	Good::Good(const Good& m_good)
	{
		name(m_good.nameGood);

		strncpy(goodSku, m_good.goodSku, max_sku_length);
		goodSku[max_sku_length] = '\0';

		strncpy(goodUnit, m_good.goodUnit, max_unit_length);
		goodUnit[max_unit_length] = '\0';

		qty_OnHand = m_good.qty_OnHand;
		taxable = m_good.taxable;
		beforeTax = m_good.beforeTax;
		qty = m_good.qty;
	}



	Good& Good::operator= (const Good& m_good)
	{

		good = m_good.good;

		strncpy(goodSku, m_good.goodSku, max_sku_length);
		goodSku[max_sku_length] = '\0';

		strncpy(goodUnit, m_good.goodUnit, max_unit_length);
		goodUnit[max_unit_length] = '\0';

		name(m_good.nameGood);

		qty_OnHand = m_good.qty_OnHand;
		qty = m_good.qty;
		beforeTax = m_good.beforeTax;
		taxable = m_good.taxable;


		return *this;
	}

	Good::~Good()
	{
		delete[] nameGood;
	}

	std::fstream& Good::store(std::fstream& file, bool newLine) const
	{
		file << good << ','<< goodSku << ','<< nameGood << ','
			<< goodUnit << ','<< taxable << ','
			<< beforeTax << ','<< qty_OnHand << ','<< qty;

		if (newLine == true)
		{
			file << std::endl;
		}

		return file;
	}

	std::fstream& Good::load(std::fstream& file)
	{
		Good temp;
		temp.nameGood = new char[max_name_length + 1];

		file.getline(temp.goodSku, max_sku_length, ',');
		file.getline(temp.nameGood, max_name_length, ',');
		file.getline(temp.goodUnit, max_unit_length, ',');
		file >> temp.taxable;
		file.ignore();
		file >> temp.beforeTax;
		file.ignore();
		file >> temp.qty_OnHand;
		file.ignore();
		file >> temp.qty;

		*this = temp;

		return file;
	}

	std::ostream& Good::write(std::ostream& os, bool linear) const
	{
		if (linear)
		{
			os << std::left
				<< std::setw(max_sku_length) << goodSku << "|"
				<< std::setw(20) << nameGood << "|"<< std::right
				<< std::fixed << std::setprecision(2)
				<< std::setw(7) << itemCost() << "|"
				<< std::setw(4) << qty_OnHand << "|"<< std::left
				<< std::setw(10) << goodUnit << "|"
				<< std::right << std::setw(4) << qty << "|";
		}

		else
		{
			os << " Sku: " << goodSku << std::endl
				<< " Name (no spaces):  " << nameGood << std::endl
				<< " Price: " << beforeTax << std::endl;

			if (taxable)
			{
				os << " Price after tax: " << itemCost() << std::endl;
			}

			else
			{
				os << " N/A" << std::endl;
			}

			os << " Quantity on hand: " << qty_OnHand << std::endl
				<< " Quantity needed:  " << qty << std::endl;
		}

		return os;
	}

	std::istream& Good::read(std::istream& is)
	{

		char t_goodSku[max_sku_length + 1];
		char* t_nameGood = new char[max_name_length + 1];
		char t_goodUnit[max_unit_length + 1];

		char t_tax;
		bool t_taxable;

		int t_qty_OnHand;
		int t_qty;
		double t_beforeTax;

		cout << " Sku: ";
		is >> t_goodSku;
		cout << " Name (no spaces): ";
		is >> t_nameGood;
		cout << " Unit: ";
		is >> t_goodUnit;
		cout << " Taxed? (y/n): ";
		is >> t_tax;

		if (t_tax != 'y' && t_tax != 'Y' && t_tax != 'n' && t_tax != 'N')
		{
			errorstate.message("Only (Y)es or (N)o are acceptable");
			is.setstate(std::ios::failbit);
		}

		else if (t_tax == 'y' || t_tax == 'Y')
		{
			t_taxable = true;
		}

		else if (t_tax == 'n' || t_tax == 'N')
		{
			t_taxable = false;
		}

		else
		{
			errorstate.message("Only (Y)es or (N)o are acceptable");
			is.setstate(std::ios::failbit);
		}

		if (!is.fail())
		{
			cout << " Price: ";
			is >> t_beforeTax;

			if (is.fail())
			{
				errorstate.message("Invalid Price Entry");
			}
		}

		if (!is.fail())
		{
			cout << " Quantity on hand: ";
			is >> t_qty_OnHand;

			if (is.fail())
			{
				errorstate.message("Invalid Quantity Entry");
			}
		}

		if (!is.fail())
		{
			cout << " Quantity needed: ";
			is >> t_qty;

			if (is.fail())
			{
				errorstate.message("Invalid Quantity Needed Entry");
			}
		}


		if (!is.fail())
		{
			Good temp = Good(t_goodSku, t_nameGood, t_goodUnit, t_qty_OnHand, t_taxable, t_beforeTax, t_qty);
			*this = temp;
		}


		return is;
	}


	bool Good::operator==(const char* str) const
	{
		bool check = false;

		if (strcmp(str, goodSku) == 0)
		{
			check = true;
		}

		return check;
	}

	double Good::total_cost() const
	{
		return ((beforeTax * qty_OnHand) * (1 + tax_rate));
	}

	void Good::quantity(int p_qty_OnHand)
	{
		qty_OnHand = p_qty_OnHand;
		return;
	}

	bool Good::isEmpty() const
	{
		bool empty = false;

		if (good == 'N')
		{
			empty = true;
		}

		return empty;
	}

	int Good::qtyNeeded() const
	{
		return qty;
	}

	int Good::quantity() const
	{
		return qty_OnHand;
	}

	bool Good::operator>(const char* p_goodSku) const
	{
		bool gt = false;

		if (strcmp(goodSku, p_goodSku) > 0)
		{
			gt = true;
		}

		return gt;
	}

	bool Good::operator>(const Good& m_good) const
	{
		bool gt = false;

		if (strcmp(nameGood, m_good.nameGood) > 0)
		{
			gt = true;
		}

		return gt;
	}

	int Good::operator+= (int numunit)
	{
		if (numunit > 0)
		{
			qty_OnHand += numunit;
		}

		return qty_OnHand;
	}

	std::ostream& operator<< (std::ostream& os, const Good& m_good)
	{
		m_good.write(os, true);

		return os;
	}

	std::istream& operator>> (std::istream& is, Good& m_good)
	{
		m_good.read(is);

		return is;
	}

	double operator+= (double& additCost, const Good& m_good)
	{
		return m_good.total_cost() + additCost;
	}
}