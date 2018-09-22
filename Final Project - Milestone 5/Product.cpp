// UPDATED - Date: 2018-08-08
// Final Project Milestone 5 - Perishable Class

// Name: Angadpreet Baidwan
// Student Number: 135421170
// Seneca Email: abaidwan1@myseneca.ca
// Date: 2018-08-01
// Final Project Milestone 3 - Product Class

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <fstream>
#include <iomanip>
#include "Product.h"

namespace AMA {

	// PRODUCT CLASS - PROTECTED MEMBER FUNCTIONS

	// Stores name of the product
	void Product::name(const char* _name) {
		if (prodName != nullptr) {
			delete[] prodName;
			prodName = nullptr;
		}
		if (_name != nullptr) {
			if (strlen(_name) > max_name_length) {
				prodName = new char[max_name_length + 1];
				strncpy(prodName, _name, max_name_length);
				prodName[max_name_length] = '\0';
			}
			else {
				prodName = new char[strlen(_name) + 1];
				strncpy(prodName, _name, strlen(_name));
				prodName[strlen(_name)] = '\0';
			}
		}
	}
	// The following 6 functions are all simple queries
	const char* Product::name() const {
		return prodName;
	}
	const char* Product::sku() const {
		return prodSKU;
	}
	const char* Product::unit() const {
		return unitDescriptor;
	}
	bool Product::taxed() const {
		return taxStatus;
	}
	double Product::price() const {
		return unitPrice;
	}
	double Product::cost() const {
		if (taxStatus) {
			return (unitPrice * (1 + taxRate));
		}
		else return unitPrice;
	}
	// Stores data in Product's ErrorState object
	void Product::message(const char* errMsg) {
		errState.message(errMsg);
	}
	// Checks if ErrorState object is clear
	bool Product::isClear() const {
		return errState.isClear();
	}

	// PRODUCT CLASS - PUBLIC MEMBER FUNCTIONS

	// Zero-One Argument Constructor
	Product::Product(char type) {
		prodType = type;
		// Setting Product to safe empty state
		prodSKU[0] = '\0';
		prodName = nullptr;
		unitDescriptor[0] = '\0';
		prodOnHand = 0;
		prodNeeded = 0;
		unitPrice = 0;
		taxStatus = true;
	}
	// 7 Argument Constructor
	Product::Product(const char* _sku, const char* _name, const char* unit, int onHand,
		bool taxable, double pricePreTax, int needed) {
		prodName = nullptr;
		name(_name);
		strncpy(prodSKU, _sku, (max_sku_length + 1));
		prodSKU[max_sku_length] = '\0';
		strncpy(unitDescriptor, unit, (max_unit_length + 1));
		unitDescriptor[max_unit_length] = '\0';
		prodOnHand = onHand;
		taxStatus = taxable;
		unitPrice = pricePreTax;
		prodNeeded = needed;
		prodType = 'N';
	}
	// init() contains logic used by both the copy constructor 
	// and the copy assignment operator
	void Product::init(const Product& src) {
		// Shallow Copy
		strncpy(prodSKU, src.prodSKU, (max_sku_length + 1));
		prodSKU[max_sku_length] = '\0';
		strncpy(unitDescriptor, src.unitDescriptor, (max_unit_length + 1));
		unitDescriptor[max_unit_length] = '\0';
		prodOnHand = src.prodOnHand;
		taxStatus = src.taxStatus;
		unitPrice = src.unitPrice;
		prodNeeded = src.prodNeeded;
		errState.message(src.errState.message());
		// Allocate dynamic memory
		if (src.prodName != nullptr) name(src.prodName);
		else prodName = nullptr;
	}
	// Copy Constructor
	Product::Product(const Product& src) {
		prodName = nullptr;
		init(src);
	}
	// Copy Assignment Operator
	Product& Product::operator=(const Product& src) {
		if (this != &src) {
			init(src);
		}
		return *this;
	}
	// Destructor for deallocating memory
	Product::~Product() {
		delete[] prodName;
		prodName = nullptr;
	}
	// Storing Product data into "ms3.txt", comma deliminated
	std::fstream& Product::store(std::fstream& file, bool newLine) const {
		file << prodType << ',';
		file << prodSKU << ',';
		file << prodName << ',';
		file << unitDescriptor << ',';
		file << taxStatus << ',';
		file << unitPrice << ',';
		file << prodOnHand << ',';
		file << prodNeeded;
		if (newLine) file << std::endl;
		return file;
	}
	// Loading data from "ms3.txt" into current object
	std::fstream& Product::load(std::fstream& file) {
		Product temp;
		file.getline(temp.prodSKU, max_sku_length + 1, ',');
		temp.prodName = new char[max_name_length + 1];
		file.getline(temp.prodName, max_name_length + 1, ',');
		file.getline(temp.unitDescriptor, max_name_length + 1, ',');
		file >> temp.taxStatus;
		file.get();
		file >> temp.unitPrice;
		file.get();
		file >> temp.prodOnHand;
		file.get();
		file >> temp.prodNeeded;
		file.get();
		*this = temp;
		return file;
	}
	// Outputs current object data
	std::ostream& Product::write(std::ostream& os, bool linear) const {
		if (isClear()) {
			if (linear) {
				os << std::setfill(' ');
				os << std::setw(max_sku_length) << std::left << prodSKU << '|'
					<< std::setw(20) << prodName << '|' << std::fixed << std::setprecision(2)
					<< std::setw(7) << std::right << cost() << '|' << std::setw(4)
					<< prodOnHand << '|' << std::setw(10) << std::left << unitDescriptor << '|' << std::setw(4)
					<< std::right << prodNeeded << '|';
			}
			else if (!linear) {
				os << " Sku: " << prodSKU << std::endl;
				os << " Name (no spaces): " << prodName << std::endl;
				os << " Price: " << unitPrice << std::endl;
				os << " Price after tax: ";
				if (taxed()) os << cost() << std::endl;
				else os << "N/A" << std::endl;
				os << " Quantity on Hand: " << prodOnHand << " " << unitDescriptor << std::endl;
				os << " Quantity needed: " << prodNeeded;
			}
		}
		else {
			os << errState.message();
		}
		return os;
	}
	// Data input, validation, setting error states
	std::istream& Product::read(std::istream& is) {
		char sku[max_sku_length + 1];
		char name[max_name_length + 1];
		char unit[max_unit_length + 1];
		int  qtyOnHand, qtyNeeded;
		double price;
		char tax;
		bool taxBool;
		std::cout << " Sku: ";
		is >> sku;
		std::cout << " Name (no spaces): ";
		is >> name;
		std::cout << " Unit: ";
		is >> unit;
		std::cout << " Taxed? (y/n): ";
		is >> tax;
		if (tax != 'y' && tax != 'Y' && tax != 'N' && tax != 'n') {
			is.setstate(std::ios::failbit);
			errState.message("Only (Y)es or (N)o are acceptable");
		}
		else if (tax == 'y' || tax == 'Y') taxBool = true;
		else if (tax == 'y' || tax == 'Y') taxBool = false;
		if (!is.fail()) {
			std::cout << " Price: ";
			is >> price;
			if (is.fail()) errState.message("Invalid Price Entry");
		}
		if (!is.fail()) {
			std::cout << " Quantity on hand: ";
			is >> qtyOnHand;
			if (is.fail()) errState.message("Invalid Quantity Entry");
		}
		if (!is.fail()) {
			std::cout << " Quantity needed: ";
			is >> qtyNeeded;
			is.ignore();
			if (is.fail()) errState.message("Invalid Quantity Needed Entry");
		}
		if (!is.fail()) {
			Product prod(sku, name, unit, qtyOnHand, taxBool, price, qtyNeeded);
			*this = prod;
		}
		return is;
	}
	// Checks if rhs is identical to sku of current object
	bool Product::operator==(const char* rhs) const {
		return (std::strcmp(prodSKU, rhs) == 0);
	}
	// Returns total cost of all on hand units
	double Product::total_cost() const {
		return (cost() * prodOnHand);
	}
	// Resets quantity on hand
	void Product::quantity(int qty) {
		prodOnHand = qty;
	}
	// Returns true if Product object is in a safe empty state
	bool Product::isEmpty() const {
		return (prodSKU[0] == '\0' && prodName == nullptr && unitDescriptor[0] == '\0' &&
			prodOnHand == 0 && prodNeeded == 0 && unitPrice == 0 && taxStatus == true);
	}
	// Returns quantity needed
	int Product::qtyNeeded() const {
		return prodNeeded;
	}
	// Returns quantity on hand
	int Product::quantity() const {
		return prodOnHand;
	}
	// Returns true if current object's sku is greater than rhs
	bool Product::operator>(const char* rhs) const {
		if (strcmp(prodSKU, rhs) > 0) return true;
		else return false;
	}
	// Checks if name of current object is greater than the name of the referenced object
	bool Product::operator>(const iProduct& rhs) const {
		if (strcmp(prodSKU, rhs.name()) > 0) return true;
		else return false;
	}
	// Updates units on hand if integer is positive and returns quantity
	int Product::operator+=(int x) {
		if (x > 0) {
			prodOnHand += x;
		}
		return prodOnHand;
	}

	// PRODUCT CLASS - HELPER FUNCTIONS

	std::ostream& operator<<(std::ostream& os, const iProduct& prod) {
		prod.write(os, true);
		return os;
	}
	std::istream& operator>>(std::istream& is, iProduct& prod) {
		prod.read(is);
		return is;
	}
	// Adds total cost of product to amount and returns it
	double operator+=(double& amount, const iProduct& prod) {
		return amount += prod.total_cost();
	}
}
