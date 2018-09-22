// Name: Angadpreet Baidwan
// Student Number: 135421170
// Date: 2018-06-05

#ifndef CRA_ACCOUNT_H
#define CRA_ACCOUNT_H

namespace sict {
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;

	class CRA_Account {
		char fam_name[max_name_length + 1];
		char giv_name[max_name_length + 1];
		int SIN;
		int tax_yr[max_yrs];
		double blnce[max_yrs];
		int yrs_stored;
	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
		void set(int year, double balance);
		bool sinCheck(int sin);
	};
}

#endif