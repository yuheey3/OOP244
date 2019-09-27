/**********************
Name : Yuki Waka
Date   : 06 10 2019
S #       : 141082180
Section: SCC
**********************/
// TODO: add file header comments here

// TODO: add header file guard here
#ifndef __PASSENGER_H__
#define __PASSENGER_H__
// TODO: declare your namespace here

namespace sict {
	class Passenger {
	private:
		char thePassenger[19];
		char theDestination[19];
		int yearDepart;
		int monthDepart;
		int dayDepart;


	public:
		Passenger();
		Passenger(const char*, const char*);
		Passenger(const char*, const char*, int, int, int);
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Passenger&) const;
	};
}
// TODO: define the Passenger class here

#endif // !__PASSENGER_h__

