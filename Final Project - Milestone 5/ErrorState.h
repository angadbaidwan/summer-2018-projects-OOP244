// Name: Angadpreet Baidwan
// Student Number: 135421170
// Seneca Email: abaidwan1@myseneca.ca
// Date: 2018-07-20
// Final Project Milestone 2 - ErrorState Class

#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H

#include <iostream>

namespace AMA {
	class ErrorState {
		char* errmsg;
	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& em) = delete;
		ErrorState& operator=(const ErrorState& em) = delete;
		virtual ~ErrorState();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message() const;
	};
	std::ostream& operator<<(std::ostream& os, const ErrorState& es);
}

#endif