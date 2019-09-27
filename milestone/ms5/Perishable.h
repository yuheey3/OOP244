// --------------------------------------------------------------
// Name    Yuki Waka       Date   2019/08/08   student#: 141082180   
/////////////////////////////////////////////////////////////////
#ifndef _PERISHABLE_H
#define _PERISHABLE_H

#include <iostream>
#include "Good.h"
#include "Date.h"

namespace aid
{
	class Perishable : public Good
	{
		Date m_date;
	public:
		Perishable();

		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const;
	};

	iGood* CreatePerishable();
}
#endif 

