// Name: Angadpreet Baidwan
// Student Number: 135421170
// Seneca Email: abaidwan1@myseneca.ca
// Date: 2018-07-19

#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

#include "Account.h"

namespace sict {
	class ChequingAccount : public Account {
		double transacFee;
		double monthlyFee;

	public:
		// TODO: constructor initializes account balance and transaction fee
		ChequingAccount(double, double, double);

		// TODDO: credit adds +ve amount to the balance
		bool credit(double);

		// TODO: debit subtracts a +ve amount from the balance
		bool debit(double);

		// TODO: month end
		void monthEnd();

		// TODO: display inserts the account information into an ostream
		void display(std::ostream&) const;

	};
}
#endif
