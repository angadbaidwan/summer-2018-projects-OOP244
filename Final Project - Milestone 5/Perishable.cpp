// Name: Angadpreet Baidwan
// Student Number: 135421170
// Seneca Email: abaidwan1@myseneca.ca
// Date: 2018-08-08
// Final Project Milestone 5 - Perishable Class

#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include "Perishable.h"

namespace AMA {
	// Constructor - sets object to safe empty state
	Perishable::Perishable() : Product::Product('P') {
		expiryDate = Date();
	}
	// Stores single file record for current object and returns reference to modified fstream object
	std::fstream& Perishable::store(std::fstream& file, bool newLine) const {
		Product::store(file, false);
		file << ',' << expiryDate;
		if (newLine) file << '\n';
		return file;
	}
	// Extracts data fields for a single file record from fstream object
	std::fstream& Perishable::load(std::fstream& file) {
		Product::load(file);
		expiryDate.read(file);
		file.get();
		return file;
	}
	// Returns reference to modified ostream object, flag identifies output format
	std::ostream& Perishable::write(std::ostream& os, bool linear) const {
		Product::write(os, linear);
		if (!isEmpty() && isClear()) {
			if (linear) {
				os << expiryDate;
			}
			else {
				os << std::endl;
				os << " Expiry date: " << expiryDate;
			}
		}
		return os;
	}
	// Populates current object with data extracted from istream object
	std::istream& Perishable::read(std::istream& is) {
		Product::read(is);
		Date temp;
		if (!is.fail()) {
			std::cout << " Expiry date (YYYY/MM/DD): ";
			is >> temp;
			if (temp.errCode() != 0) {
				if (temp.errCode() == 1) message("Invalid Date Entry");
				else if (temp.errCode() == 2) message("Invalid Year in Date Entry");
				else if (temp.errCode() == 3) message("Invalid Month in Date Entry");
				else if (temp.errCode() == 4) message("Invalid Day in Date Entry");
				is.setstate(std::ios::failbit);
			}
			else {
				expiryDate = temp;
			}
		}
		return is;
	}
	// Query returns expiry date for perishable product
	const Date& Perishable::expiry() const {
		return expiryDate;
	}
}