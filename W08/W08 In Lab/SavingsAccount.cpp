// Name: Angadpreet Baidwan
// Student Number: 135421170
// Seneca Email: abaidwan1@myseneca.ca
// Date: 2018-07-19

#include "SavingsAccount.h"

namespace sict {
	SavingsAccount::SavingsAccount(double balance, double interest) : Account(balance) {
		if (interest > 0) {
			interestSA = interest;
		}
		else interestSA = 0.0;
	}
	void SavingsAccount::monthEnd() {
		double bal = balance() * (1 + interestSA);
		*this = SavingsAccount(bal, interestSA);
	}
	void SavingsAccount::display(std::ostream& os) const {
		os.setf(std::ios::fixed);
		os.precision(2);
		os << "Account type: Savings" << std::endl;
		os << "Balance: $" << balance() << std::endl;
		os << "Interest Rate (%): " << (100 * interestSA) << std::endl;
	}
}