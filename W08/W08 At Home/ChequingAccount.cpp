// Name: Angadpreet Baidwan
// Student Number: 135421170
// Seneca Email: abaidwan1@myseneca.ca
// Date: 2018-07-19

// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

#include "ChequingAccount.h"

namespace sict {
	// constructor initializes balance and transaction fee
	//
	ChequingAccount::ChequingAccount(double balance, double t_fee, double m_fee) : Account(balance) {
		if (t_fee > 0) transacFee = t_fee;
		else transacFee = 0.0;
		if (m_fee > 0) monthlyFee = m_fee;
		else monthlyFee = 0.0;
	}

	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//
	bool ChequingAccount::credit(double amnt) {
		if (Account::credit(amnt)) {
			Account::debit(transacFee);
			return true;
		}
		else return false;
	}


	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//
	bool ChequingAccount::debit(double amnt) {
		if (Account::debit(amnt)) {
			Account::debit(transacFee);
			return true;
		}
		else return false;
	}

	// monthEnd debits month end fee
	//
	void ChequingAccount::monthEnd() {
		debit(monthlyFee);
	}


	// display inserts account information into ostream os
	//
	void ChequingAccount::display(std::ostream& os) const {
		os.setf(std::ios::fixed);
		os.precision(2);
		os << "Account type: Chequing" << std::endl;
		os << "Balance: $" << balance() << std::endl;
		os << "Per Transaction Fee: " << transacFee << std::endl;
		os << "Monthly Fee: " << monthlyFee << std::endl;
	}



}