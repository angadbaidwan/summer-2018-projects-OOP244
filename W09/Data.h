// Name: Angadpreet Baidwan
// Student Number: 135421170
// Seneca Email: abaidwan1@myseneca.ca
// Date: 2018-07-26

#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <sstream>

namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;
	const int COLUMN_WIDTH = 15;

	// max returns the largest item in data
	//
	template<typename T>
	T max(const T* data, int n) {
		T max = SMALLEST_NUMBER;
		for (int i = 0; i < n; i++) {
			if (data[i] > max && data[i] <= LARGEST_NUMBER && data[i] >= SMALLEST_NUMBER) {
				max = data[i];
			}
		}
		return max;
	}

	// min returns the smallest item in data
	//
	template<typename T>
	T min(const T* data, int n) {
		T min = LARGEST_NUMBER;
		for (int i = 0; i < n; i++) {
			if (data[i] < min && data[i] <= LARGEST_NUMBER && data[i] >= SMALLEST_NUMBER) {
				min = data[i];
			}
		}
		return min;
	}

	// sum returns the sum of n items in data
	//    
	template<typename T>
	T sum(const T* data, int n) {
		T sum = 0;
		for (int i = 0; i < n; i++) {
			sum += data[i];
		}
		return sum;
	}

	// average returns the average of n items in data
	//
	template<typename T>
	double average(const T* data, int n) {
		double avg = sum(data, n) / n;
		return avg;
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//
	template<typename T>
	bool read(std::istream& input, T* data, int n) {
		char delim = ',';
		char temp[2000];

		input.ignore();
		for (int i = 0; i < n && !input.fail(); i++)
		{
			delim = i < (n - 1) ? ',' : '\n';
			input.get(temp, 2000, delim);
			if (delim == ',') input.ignore();
			std::stringstream ss(temp);
			ss >> data[i];
			if (ss.fail()) input.setstate(std::ios::failbit);
		}
		return !input.fail();
	}
	
	// display inserts n items of data into std::cout
	//
	template<typename T>
	void display(const char* name, const T* data, int n) {
		std::cout.width(20);
		std::cout << name;
		for (int i = 0; i < n; i++) {
			std::cout.width(COLUMN_WIDTH);
			std::cout << data[i];
		}
		std::cout << std::endl;
	}

	bool readRow(std::istream& input, const char* name, int* data, int n);
	bool readRow(std::istream& input, const char* name, double* data, int n);
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

#endif