// Name: Angadpreet Baidwan
// Student Number: 135421170
// Seneca Email: abaidwan1@myseneca.ca
// Date: 2018-07-05

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Contact.h"
using namespace std;

namespace sict {
	Contact::Contact() {
		name[0] = '\0';
		phone = nullptr;
		num = -1;
	}
	Contact::Contact(const char* p_name, const long long* p_phone, int p_num) {
		if (p_name != nullptr && p_name[0] != '\0' && p_num >= 0) {
			int valid_num = 0;
			for (int i = 0; i < p_num; i++) {
				if (isValidNum(p_phone[i])) {
					valid_num++;
				}
			}
			strncpy(name, p_name, SIZE);
			name[SIZE-1] = '\0';
			num = valid_num;
			phone = new long long[valid_num];
			int j= 0;
			for (int i = 0; j < valid_num; i++) {
				if (isValidNum(p_phone[i])) {
					phone[j] = p_phone[i];
					j++;
				}
			}
		}
		else {
			*this = Contact();
		}
	}
	Contact::~Contact() {
		delete[] phone;
	}
	bool Contact::isEmpty() const {
		return (name[0] == '\0' && phone == nullptr && num == -1);
	}
	void Contact::display() const {
		if (isEmpty()) {
			cout << "Empty contact!" << endl;
;		}
		else {
			cout << name << endl;
			for (int i = 0; i < num; i++) {
				long long temp = phone[i];
				cout.fill('0');
				cout << "(+" << (int)(temp / (long long)1e10) << ") ";
				temp -= (int)(temp / (long long)1e10) * (long long)1e10;
				cout << (int)(temp / (long long)1e7) << " ";
				cout.width(3);
				temp -= (int)(temp / (long long)1e7) * (long long)1e7;
				cout << (int)(temp / (long long)1e4) << "-";
				cout.width(4);
				temp -= (int)(temp / (long long)1e4) * (long long)1e4;
				cout << temp << endl;
			}
		}
	}
	bool Contact::isValidNum(long long v_phone) const {
		if (v_phone / (long long)1e12 == 0 && v_phone / (long long)1e10 != 0 && v_phone) {
			v_phone -= (int)(v_phone / (long long)1e10) * (long long)1e10;
			if (v_phone / (long long)1e9 != 0) {
				v_phone -= (int)(v_phone / (long long)1e7) * (long long)1e7;
				if (v_phone / (long long)1e6 != 0) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
}