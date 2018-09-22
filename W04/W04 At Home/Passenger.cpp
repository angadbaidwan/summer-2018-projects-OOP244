// Name: Angadpreet Baidwan
// Student Number: 135421170
// Date: 2018-06-12


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Passenger.h"

namespace sict {
	Passenger::Passenger(const char* _name, const char* _dest, int _year, int _month, int _day) {
		if ((_name != nullptr && _name[0] != '\0') && (_dest != nullptr && _dest[0] != '\0')
			&& (_year >= 2017 && _year <= 2020) && (_month >= 1 && _month <= 12) && (_day >= 1 && _day <= 31)) {
			strncpy(nameP, _name, SIZE - 1);
			nameP[SIZE - 1] = '\0';
			strncpy(dest, _dest, SIZE - 1);
			dest[SIZE - 1] = '\0';
			year = _year;
			month = _month;
			day = _day;
		}
		else {
			setEmpty();
		}
	}
	Passenger::Passenger() {
		setEmpty();
	}
	Passenger::Passenger(const char* _name, const char* _dest) {
		if ((_name != nullptr && _name[0] != '\0') && (_dest != nullptr && _dest[0] != '\0')) {
			strncpy(nameP, _name, SIZE - 1);
			nameP[SIZE - 1] = '\0';
			strncpy(dest, _dest, SIZE - 1);
			dest[SIZE - 1] = '\0';
		}
		else {
			setEmpty();
		}
	}
	bool Passenger::isEmpty() const {
		if ((nameP == nullptr || nameP[0] == '\0') || (dest == nullptr || dest[0] == '\0')) {
			return true;
		}
		else {
			return false;
		}
	}
	void Passenger::display() const {
		if (!isEmpty()) {
			cout << nameP << " - " << dest << " on " << year << "/";
			cout.width(2);
			cout.fill('0');
			cout << month << "/" << day << endl;
		}
		else {
			cout << "No passenger!" << endl;
		}
	}
	const char* Passenger::name() const {
		return nameP;
	}
	bool Passenger::canTravelWith(const Passenger& psngr) const {
		return (strcmp(dest, psngr.dest) == 0 && year == psngr.year && month == psngr.month && day == psngr.day);
	}
	void Passenger::setEmpty() {
		nameP[0] = '\0';
		dest[0] = '\0';
		year = 0;
		month = 0;
		day = 0;
	}
}