// Final Project Milestone 1
//
// Version 1.0
// Name: Angadpreet Baidwan
// Student Number: 135421170
// Seneca Email: abaidwan1@myseneca.ca
// Date: 2018-07-12
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include "Date.h"

namespace AMA {

  // number of days in month mon_ and year year_
  //
  int Date::mdays(int mon, int year)const {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int month = mon >= 1 && mon <= 12 ? mon : 13;
    month--;
    return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}
  void Date::errCode(int errorCode) {
	  errState = errorCode;
  }
  Date::Date() {
	  year = 0;
	  month = 0;
	  day = 0;
	  comparator = 0;
	  errCode(NO_ERROR);
  }
  Date::Date(int _year, int _month, int _day) {
	  if (_year == 0 && _month == 0 && _day == 0) errCode(CIN_FAILED);
	  else if (_year < min_year || _year > max_year) errCode(YEAR_ERROR);
	  else if (_month < 1 || _month > 12) errCode(MON_ERROR);
	  else if (_day < 1 || _day > mdays(_month, _year)) errCode(DAY_ERROR);
	  else errCode(NO_ERROR);

	  if (!bad()) {
		  year = _year;
		  month = _month;
		  day = _day;
		  comparator = year * 372 + month * 13 + day;
	  }
	  else {
		  *this = Date();
	  }
  }
  bool Date::isEmpty() const {
	  return (year == 0 && month == 0 && day == 0);
  }
  bool Date::operator==(const Date& rhs) const {
	  if (comparator == rhs.comparator) return true;
	  else return false;
  }
  bool Date::operator!=(const Date& rhs) const {
	  if (comparator != rhs.comparator) return true;
	  else return false;
  }
  bool Date::operator<(const Date& rhs) const {
	  if (comparator < rhs.comparator) return true;
	  else return false;
  }
  bool Date::operator>(const Date& rhs) const {
	  if (comparator > rhs.comparator) return true;
	  else return false;
  }
  bool Date::operator<=(const Date& rhs) const {
	  if (comparator <= rhs.comparator) return true;
	  else return false;
  }
  bool Date::operator>=(const Date& rhs) const {
	  if (comparator >= rhs.comparator) return true;
	  else return false;
  }
  int Date::errCode() const {
	  return errState;
  }
  int Date::bad() const {
	  return (errState != NO_ERROR);
  }
  std::istream& Date::read(std::istream& istr) {
	  char fill;
	  int _year, _month, _day;

	  istr >> _year >> fill >> _month >> fill >> _day;

	  if (istr.fail()) {
		  errCode(CIN_FAILED);
	  }
	  else if (_year < min_year || _year > max_year) {
		  errCode(YEAR_ERROR);
	  }
	  else if (_month < 1 || _month > 12) {
		  errCode(MON_ERROR);
	  }
	  else if (_day < 1 || _day > mdays(_month, _year)) {
		  errCode(DAY_ERROR);
	  }
	  else {
		  *this = Date(_year, _month, _day);
	  }
	  return istr;
  }
  std::ostream& Date::write(std::ostream& ostr) const {
	  ostr.fill('0');
	  ostr << year << "/";
	  ostr.width(2);
	  ostr << month << "/";
	  ostr.width(2);
	  ostr << day;
	  return ostr;
  }
  std::istream& operator>>(std::istream& is, Date& d) {
	  return d.read(is);
  }
  std::ostream& operator<<(std::ostream& os, const Date& d) {
	  return d.write(os);
  }
}
