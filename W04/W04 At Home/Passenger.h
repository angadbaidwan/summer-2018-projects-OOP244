// Name: Angadpreet Baidwan
// Student Number: 135421170
// Date: 2018-06-12

// TODO: add header file guard here
#ifndef PASSENGER_H
#define PASSENGER_H
// TODO: declare your namespace here
namespace sict {
	const int SIZE = 32;
	// TODO: define the Passenger class here
	class Passenger {
		char nameP[SIZE];
		char dest[SIZE];
		int year;
		int month;
		int day;
	public:
		Passenger();
		Passenger(const char*, const char*);
		Passenger(const char*, const char*, int, int, int);
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Passenger&) const;
		void setEmpty();
	};

}
#endif