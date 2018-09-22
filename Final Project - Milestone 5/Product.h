// UPDATED - Date: 2018-08-08
// Final Project Milestone 5 - Perishable Class

// Name: Angadpreet Baidwan
// Student Number: 135421170
// Seneca Email: abaidwan1@myseneca.ca
// Date: 2018-08-01
// Final Project Milestone 3 - Product Class

#include "ErrorState.h"
#include "iProduct.h"

#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H

namespace AMA {
	const int max_sku_length = 7; // Max # of char in a sku
	const int max_unit_length = 10; // Max # of char in units' descriptor for a product
	const int max_name_length = 75; // Max # of char in user's name descriptor for a product length
	const double taxRate = 0.13; // Current Tax Rate

	class Product : public iProduct {
		char prodType;
		char prodSKU[max_sku_length + 1];
		char unitDescriptor[max_unit_length + 1];
		char* prodName;
		int prodOnHand;
		int prodNeeded;
		double unitPrice;
		bool taxStatus;
		ErrorState errState;
	protected:
		void name(const char*);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double price() const;
		double cost() const;
		void message(const char*);
		bool isClear() const;
	public:
		Product(char type = 'N');
		Product(const char* _sku, const char* _name, const char* unit, int onHand = 0,
			bool taxable = true, double pricePreTax = 0, int needed = 0);
		void init(const Product& src); // contains logic used by copy constructor & operator
		Product(const Product&);
		Product& operator=(const Product&);
		~Product();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		bool operator>(const iProduct&) const;
		int operator+=(int);
	};
	std::ostream& operator<<(std::ostream&, const iProduct&);
	std::istream& operator>>(std::istream&, iProduct&);
	double operator+=(double&, const iProduct&);
}
#endif
