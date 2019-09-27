/**********************
Name : Yuki Waka
Date   : 06 06 2019
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
	
	public:
		Passenger();
		Passenger(const char*, const char*);
		bool isEmpty() const;
		void display() const;
	};
}
// TODO: define the Passenger class here

#endif // !__PASSENGER_h__
