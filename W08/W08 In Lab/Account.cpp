// Name: Angadpreet Baidwan
// Student Number: 135421170
// Seneca Email: abaidwan1@myseneca.ca
// Date: 2018-07-19

#include "Account.h"

namespace sict {
	Account::Account(double amount) {
		if (amount > 0) _balance = amount;
		else _balance = 0.0;
	}
	bool Account::credit(double amount) {
		if (amount > 0) {
			_balance += amount;
			return true;
		}	
		else return false;
	}
	bool Account::debit(double amount) {
		if (amount > 0) {
			_balance -= amount;
			return true;
		}
		else return false;
	}
	double Account::balance() const {
		return _balance;
	}
}