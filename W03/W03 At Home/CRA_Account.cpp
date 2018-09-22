// Name: Angadpreet Baidwan
// Student Number: 135421170
// Date: 2018-06-05

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "CRA_Account.h"

namespace sict {
	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
		if (sinCheck(sin) && familyName[0] != '\0' && givenName[0] != '\0') {
			SIN = sin;
			strncpy(fam_name, familyName, max_name_length);
			fam_name[max_name_length] = '\0';
			strncpy(giv_name, givenName, max_name_length);
			giv_name[max_name_length] = '\0';
			yrs_stored = 0;
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
			for (int i = 0; i < max_yrs; i++) {
				if (blnce[i] > 2) {
					cout << "Year (" << tax_yr[i] << ") balance owing: " << fixed << setprecision(2) << blnce[i] << endl;
				}
				else if (blnce[i] < -2) {
					cout << "Year (" << tax_yr[i] << ") refund due: " << fixed << setprecision(2) << -blnce[i] << endl;
				}
				else {
					cout << "Year (" << tax_yr[i] << ") No balance owing or refund due!" << endl;
				}
			}
		}
		else {
			cout << "Account object is empty!" << endl;
		}
	}
	void CRA_Account::set(int year, double balance) {
		if (sinCheck(SIN)) {
			if (yrs_stored < max_yrs) {
				tax_yr[yrs_stored] = year;
				blnce[yrs_stored] = balance;
				yrs_stored++;
			}
		}
	}
	bool CRA_Account::sinCheck(int sin) {
		int num = sin / 10;
		int tmp, tmpSum;
		int sum = 0;
		for (int i = 0; i < 8; i++) {
			if (i % 2 == 0) {
				if (((num % 10) * 2) > 9) {
					tmp = (num % 10) * 2;
					tmpSum = (tmp / 10) % 10 + tmp % 10;
					sum = sum + tmpSum;
				}
				else {
					sum = sum + (num % 10) * 2;
				}
			}
			else {
				sum = sum + num % 10;
			}
			num = num / 10;
		}
		int diff;
		if (sum % 10 != 0) {
			diff = 10 - sum % 10;
		}
		else {
			diff = 0;
		}
		return ((diff == sin % 10) && sin <= max_sin && sin >= min_sin);
	}
}