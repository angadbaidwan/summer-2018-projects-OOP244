// Name: Angadpreet Baidwan
// Student Number: 135421170
// Date: 2018-06-14

// TODO: insert header files
#include <iostream>
using namespace std;
#include "Fraction.h"

// TODO: continue the namespace
namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		num = -1;
		den = -1;
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int a, int b) {
		if (a >= 0 && b > 0) {
			num = a;
			den = b;
			reduce();
		}
		else {
			num = -1;
			den = -1;
		}
	}
	// TODO: implement the max query
	int Fraction::max() const {
		if (num > den) {
			return num;
		}
		else {
			return den;
		}
	}
	// TODO: implement the min query
	int Fraction::min() const {
		if (num < den) {
			return num;
		}
		else {
			return den;
		}
	}
	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}
	// TODO: implement the reduce modifier
	void Fraction::reduce() {
		int _gcd = gcd();
		num = num / _gcd;
		den = den / _gcd;
	}
	// TODO: implement the display query
	void Fraction::display() const {
		if (num >= 0 && den > 0 && den != 1) {
			cout << num << "/" << den;
		}
		else if (num >= 0 && den > 0 && den == 1) {
			cout << num;
		}
		else {
			cout << "no fraction stored";
		}
	}
	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		if (num == -1 || den == -1) {
			return true;
		}
		else {
			return false;
		}
	}
	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const {
		if (!isEmpty() && !rhs.isEmpty()) {
			Fraction result;
			result.num = num * rhs.den + den * rhs.num;
			result.den = den * rhs.den;
			result.reduce();
			return result;
		}
		else {
			return Fraction();
		}
	}
}