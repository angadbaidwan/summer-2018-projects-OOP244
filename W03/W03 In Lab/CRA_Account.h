// Name: Angadpreet Baidwan
// Student Number: 135421170
// Date: 2018-05-31

#ifndef CRA_ACCOUNT_H
#define CRA_ACCOUNT_H

namespace sict {
	const int max_name_length = 40, min_sin = 100000000, max_sin = 999999999;

	class CRA_Account {
		char fam_name[max_name_length + 1];
		char giv_name[max_name_length + 1];
		int SIN;
	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
	};
}

#endif