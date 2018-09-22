// Name: Angadpreet Baidwan
// Student Number: 135421170
// Date: 2018-05-31

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;
#include "CRA_Account.h"

namespace sict {
	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
		if (sin <= max_sin && sin >= min_sin) {
			SIN = sin;
			strncpy(fam_name, familyName, max_name_length);
			fam_name[max_name_length] = '\0';
			strncpy(giv_name, givenName, max_name_length);
			giv_name[max_name_length] = '\0';
		}
		else {
			SIN = -1;
		}
	}
	bool CRA_Account::isEmpty() const {
		if (SIN == -1) {
			return true;
		}
		else {
			return false;
		}
	}
	void CRA_Account::display() const {
		if (SIN != -1) {
			cout << "Family Name: " << fam_name << endl;
			cout << "Given Name : " << giv_name << endl;
			cout << "CRA Account: " << SIN << endl;
		}
		else {
			cout << "Account object is empty!" << endl;
		}
	}
}