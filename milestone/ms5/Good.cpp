// --------------------------------------------------------------
// Name    Yuki Waka       Date   2019/08/08   student#: 141082180   
/////////////////////////////////////////////////////////////////
#include <cstring>
#include <string>
#include <fstream>
#include <iomanip>
#include "Good.h"

using std::cin;
using std::cout;

namespace aid {

	Good::Good(char p_goodType)
	{
		goodType = p_goodType;
		goodSku[0] = '\0';
		goodUnit[0] = '\0';
		goodName = nullptr;
		qtyOnHand = 0;
		qtyReq = 0;
		priceBefore = 0.0;
		taxable = false;

	}

	Good::Good(const char* p_goodSku, const char* p_goodName, const char* p_goodUnit, int p_qty, bool p_taxable, double p_price, int p_qtyReq)
	{
		name(p_goodName);

		strncpy(goodSku, p_goodSku, max_sku_length);
		goodSku[max_sku_length] = '\0';

		strncpy(goodUnit, p_goodUnit, max_unit_length);
		goodUnit[max_unit_length] = '\0';

		qtyOnHand = p_qty;
		taxable = p_taxable;
		priceBefore = p_price;
		qtyReq = p_qtyReq;
	}

	Good::Good(const Good& p_good)
	{
		name(p_good.goodName);

		strncpy(goodSku, p_good.goodSku, max_sku_length);
		goodSku[max_sku_length] = '\0';

		strncpy(goodUnit, p_good.goodUnit, max_unit_length);
		goodUnit[max_unit_length] = '\0';

		qtyOnHand = p_good.qtyOnHand;
		taxable = p_good.taxable;
		priceBefore = p_good.priceBefore;
		qtyReq = p_good.qtyReq;
	}

	Good::~Good()
	{
		delete[] goodName;
	}

	Good& Good::operator= (const Good& good)
	{

		goodType = good.goodType;

		strncpy(goodSku, good.goodSku, max_sku_length);
		goodSku[max_sku_length] = '\0';

		strncpy(goodUnit, good.goodUnit, max_unit_length);
		goodUnit[max_unit_length] = '\0';

		name(good.goodName);

		qtyOnHand = good.qtyOnHand;
		qtyReq = good.qtyReq;
		priceBefore = good.priceBefore;
		taxable = good.taxable;


		return *this;
	}

	std::fstream& Good::store(std::fstream& file, bool newLine) const
	{
		file << goodType << ','
			<< goodSku << ','
			<< goodName << ','
			<< goodUnit << ','
			<< taxable << ','
			<< priceBefore << ','
			<< qtyOnHand << ','
			<< qtyReq;

		if (newLine == true)
		{
			file << std::endl;
		}

		return file;
	}

	std::fstream& Good::load(std::fstream& file)
	{
		Good temp;
		temp.goodName = new char[max_name_length + 1];

		file.getline(temp.goodSku, max_sku_length, ',');
		file.getline(temp.goodName, max_name_length, ',');
		file.getline(temp.goodUnit, max_unit_length, ',');
		file >> temp.taxable;
		file.ignore();
		file >> temp.priceBefore;
		file.ignore();
		file >> temp.qtyOnHand;
		file.ignore();
		file >> temp.qtyReq;
		file.ignore();

		*this = temp;

		return file;
	}


	std::ostream& Good::write(std::ostream& os, bool linear) const
	{
		if (!er.isClear())
		{
			os << er.message();
		}
		else if ((linear) && goodSku[0] == '\0') {

		}
		else if (linear)
		{
			os << std::setfill(' ') << std::left
				<< std::setw(max_sku_length) << goodSku << "|"
				<< std::setw(20) << goodName << "|"
				<< std::right
				<< std::fixed << std::setprecision(2)
				<< std::setw(7) << cost() << "|"
				<< std::setw(4) << qtyOnHand << "|"
				<< std::left
				<< std::setw(10) << goodUnit << "|"
				<< std::right
				<< std::setw(4) << qtyReq << "|";
		}

		else
		{
			os << " Sku: " << goodSku << std::endl
				<< " Name (no spaces): " << goodName << std::endl
				<< " Price: " << priceBefore << std::endl
				<< " Price after tax: ";

			if (taxable)
			{
				os << cost() << std::endl;
			}

			else
			{
				os << " N/A" << std::endl;
			}

			os << " Quantity on Hand: " << qtyOnHand << ' ' << goodUnit << std::endl
				<< " Quantity needed: " << qtyReq;
		}

		return os;
	}



	std::istream& Good::read(std::istream& is)
	{
		char t_taxable;
		char * t_goodName = new char[max_name_length + 1];


		if (!is.fail())
		{
			cout << " Sku: ";
			is >> goodSku;
			cin.ignore();


			cout << " Name (no spaces): ";
			is >> t_goodName;
			name(t_goodName);

			cout << " Unit: ";
			is >> goodUnit;

			cout << " Taxed? (y/n): ";
			is >> t_taxable;

			if (!is.fail())
			{
				if (t_taxable != 'y' && t_taxable != 'Y' && t_taxable != 'n' && t_taxable != 'N')
				{
					er.message("Only (Y)es or (N)o are acceptable");
					is.setstate(std::ios::failbit);
				}

				else {

					if (t_taxable == 'y' || t_taxable == 'Y')
					{
						taxable = true;
					}

					else 
					{
						taxable = false;
					}

					cout << " Price: ";
					is >> priceBefore;

					if (is.fail())
					{
						is.setstate(std::ios::failbit);
						er.message("Invalid Price Entry");
					}

					else
					{
						cout << " Quantity on hand: ";
						is >> qtyOnHand;

						if (is.fail())
						{
							er.message("Invalid Quantity Entry");
							is.setstate(std::ios::failbit);
						}

						else
						{
							cout << " Quantity needed: ";
							is >> qtyReq;
							cin.ignore();

							if (is.fail())
							{
								er.message("Invalid Quantity Needed Entry");
								is.setstate(std::ios::failbit);
							}


							if (!is.fail())
							{
								er.clear();
							}
						}
					}
				}
			}

			else
			{
				is.setstate(std::ios::failbit);
				er.message("Only (Y)es or (N)o are acceptable");
			}

		}
		return is;
	}

	void Good::name(const char* p_goodName)
	{
		if (p_goodName != nullptr)
		{
			int i;
			for (i = 0; p_goodName[i] != '\0' || i <= max_name_length; i++);

			goodName = new char[i + 1];

			strncpy(goodName, p_goodName, i);
			goodName[i] = '\0';
		}

		else
		{
			delete[] goodName;
		}

		return;
	}

	const char* Good::name() const
	{
		return goodName;
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

	double Good::price() const
	{
		return priceBefore;
	}

	double Good::cost() const
	{
		double cost;

		if (taxable)
		{
			cost = priceBefore * (1 + taxRate);
		}

		else
		{
			cost = priceBefore;
		}


		return cost;
	}

	void Good::message(const char* errMsg)
	{
		er.message(errMsg);

		return;
	}

	bool Good::isClear() const
	{
		bool clear = false;

		clear = er.isClear();

		return clear;
	}

	bool Good::operator==(const char* str) const
	{
		bool match = false;

		if (strcmp(str, goodSku) == 0)
		{
			match = true;
		}

		return match;
	}

	double Good::total_cost() const
	{
		return ((priceBefore * qtyOnHand) * (1 + taxRate));
	}

	void Good::quantity(int p_qtyOnHand)
	{
		qtyOnHand = p_qtyOnHand;
		return;
	}

	bool Good::isEmpty() const
	{
		bool empty = false;

		if (goodName == nullptr)
		{
			empty = true;
		}

		return empty;
	}

	int Good::qtyNeeded() const
	{
		return qtyReq;
	}

	int Good::quantity() const
	{
		return qtyOnHand;
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

	bool Good::operator>(const iGood& p_good) const
	{
		bool gt = false;

		if (strcmp(goodName, p_good.name()) > 0)
		{
			gt = true;
		}

		return gt;
	}

	int Good::operator+= (int additUnits)
	{
		if (additUnits > 0)
		{
			qtyOnHand += additUnits;
		}

		return qtyOnHand;
	}

	std::ostream& operator<< (std::ostream& os, const iGood& p_good)
	{
		p_good.write(os, true);

		return os;
	}

	std::istream& operator>> (std::istream& is, iGood& p_good)
	{
		p_good.read(is);

		return is;
	}

	double operator+= (double& additCost, const iGood& p_good)
	{
		return p_good.total_cost() + additCost;
	}
}