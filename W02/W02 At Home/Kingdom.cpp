/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date: 2018-05-29
// Name: Angadpreet Baidwan
// Student #:135421170
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: include the necessary headers
#include <iostream>
#include "Kingdom.h"
using namespace std;

// TODO: the sict namespace
namespace sict {
	// TODO:definition for display(...) 
	void display(const Kingdom& kingdom) {
		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
	}
	void display(const Kingdom* kingdoms, int num) {
		int totalPopulation = 0;
		cout << "------------------------------\n";
		cout << "Kingdoms of SICT\n";
		cout << "------------------------------\n";
		for (int i = 1; i <= num; i++) {
			cout << i << ". ";
			display(kingdoms[i - 1]);
			totalPopulation += kingdoms[i - 1].m_population;
		}
		cout << "------------------------------\n";
		cout << "Total population of SICT: " << totalPopulation << endl;
		cout << "------------------------------\n";
	}
}