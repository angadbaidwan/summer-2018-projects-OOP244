// Name: Angadpreet Baidwan
// Student Number: 135421170
// Date: 2018-06-07

// TODO: add file header comments here

// TODO: add your headers here
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
#include "Passenger.h"

// TODO: continue your namespace here
namespace sict {
	// TODO: implement the default constructor here
	Passenger::Passenger() {
		name[0] = '\0';
		dest[0] = '\0';
	}
	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* _name, const char* _dest) {
		if ((_name != nullptr && _name[0] != '\0') && (_dest != nullptr && _dest[0] != '\0')) {
			strcpy(name, _name);
			strcpy(dest, _dest);
		}
		else {
			name[0] = '\0';
			dest[0] = '\0';
		}
	}
	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		if ((name == nullptr || name[0] == '\0') || (dest == nullptr || dest[0] == '\0')) {
			return true;
		}
		else {
			return false;
		}
	}
	// TODO: implement display query here
	void Passenger::display() const {
		if (!isEmpty()) {
			cout << name << " - " << dest << endl;
		}
		else {
			cout << "No passenger!" << endl;
		}
	}
}