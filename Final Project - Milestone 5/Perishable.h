// Name: Angadpreet Baidwan
// Student Number: 135421170
// Seneca Email: abaidwan1@myseneca.ca
// Date: 2018-08-08
// Final Project Milestone 5 - Perishable Class

#include "Date.h"
#include "Product.h"

#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H

namespace AMA {
	class Perishable : public Product {
		Date expiryDate;
	public: 
		Perishable();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const;
	};
}

#endif