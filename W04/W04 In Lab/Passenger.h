// Name: Angadpreet Baidwan
// Student Number: 135421170
// Date: 2018-06-07

// TODO: add header file guard here
#ifndef PASSENGER_H
#define PASSENGER_H
#define SIZE 32
// TODO: declare your namespace here
namespace sict {
	// TODO: define the Passenger class here
	class Passenger {
		char name[SIZE];
		char dest[SIZE];
	public:
		Passenger();
		Passenger(const char*, const char*);
		bool isEmpty() const;
		void display() const;
	};

}
#endif