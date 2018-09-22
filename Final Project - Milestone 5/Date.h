// Final Project Milestone 1
//
// Version 1.0
// Name: Angadpreet Baidwan
// Student Number: 135421170
// Seneca Email: abaidwan1@myseneca.ca
// Date: 2018-07-12

// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H

#include <iostream>

namespace AMA {
	const int min_year = 2000;
	const int max_year = 2030;
	int const NO_ERROR = 0;
	int const CIN_FAILED = 1;
	int const YEAR_ERROR = 2;
	int const MON_ERROR = 3;
	int const DAY_ERROR = 4;
	class Date {
		int year;
		int month;
		int day;
		int comparator;
		int errState;
		int mdays(int, int)const;
		void errCode(int);
	public:
		Date();
		Date(int, int, int);
		bool isEmpty() const;
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;
		int errCode() const;
		int bad() const;
		std::istream& read(std::istream & istr);
		std::ostream& write(std::ostream& ostr) const;
	};
	std::istream& operator>>(std::istream&, Date&);
	std::ostream& operator<<(std::ostream&, const Date&);
}
#endif