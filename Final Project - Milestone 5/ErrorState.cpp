// Name: Angadpreet Baidwan
// Student Number: 135421170
// Seneca Email: abaidwan1@myseneca.ca
// Date: 2018-07-20
// Final Project Milestone 2 - ErrorState Class

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "ErrorState.h"

namespace AMA {
	ErrorState::ErrorState(const char* errorMessage) {
		errmsg = nullptr;
		message(errorMessage);
	}
	ErrorState::~ErrorState() {
		delete[] errmsg;
	}
	void ErrorState::clear() {
		message('\0');
	}
	bool ErrorState::isClear() const {
		return (errmsg[0] == '\0');
	}
	void ErrorState::message(const char* str) {
		delete[] errmsg;
		errmsg = nullptr;
		if (str == nullptr || str[0] == '\0') {
			errmsg = new char[1];
			errmsg[0] = '\0';
		}
		else {
			errmsg = new char[strlen(str) + 1];
			strncpy(errmsg, str, strlen(str));
			errmsg[strlen(str)] = '\0';
		}
	}
	const char* ErrorState::message() const {
		return errmsg;
	}
	std::ostream& operator<<(std::ostream& os, const ErrorState& es) {
		if (!es.isClear()) {
			os << es.message();
		}
		return os;
	}
}