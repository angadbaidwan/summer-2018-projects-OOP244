// Name: Angadpreet Baidwan
// Student Number: 135421170
// Seneca Email: abaidwan1@myseneca.ca
// Date: 2018-07-19

#include "SavingsAccount.h" 

namespace sict {

	// define interest rate
	//
	const double interest = 0.05;

	// TODO: Allocator function
	//
	iAccount* CreateAccount(const char* acc, double bal_amount) {
		iAccount* p = nullptr;
		if (acc[0] == 'S') {
			p = new SavingsAccount(bal_amount, interest);
		}
		else {
			p = nullptr;
		}
		return p;
	}
}
