// Name: Angadpreet Baidwan
// Student Number: 135421170
// Seneca Email: abaidwan1@myseneca.ca
// Date: 2018-07-17

#define _CRT_SECURE_NO_WARNINGS

#include "SuperHero.h"

namespace sict {
	SuperHero::SuperHero() : Hero() {
		s_atk = 0;
		s_def = 0;
	}
	SuperHero::SuperHero(const char* _name, const int _hp, const int _str, const int _s_atk, const int _s_def) : Hero(_name, _hp, _str) {
		if (!isEmpty()) {
			s_atk = _s_atk;
			s_def = _s_def;
		}
		else {
			*this = SuperHero();
		}
	}
	int SuperHero::attackStrength() const {
		if (!isEmpty()) {
			return (s_atk + Hero::attackStrength());
		}
		else {
			return 0;
		}
	}
	int SuperHero::defend() const {
		if (!isEmpty()) return s_def;
		else return 0;
	}
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		SuperHero firstH = first;
		SuperHero secondH = second;
		int round = 0;
		for (int i = 0; i < max_rounds && firstH.isAlive() && secondH.isAlive(); i++) {
			secondH -= (firstH.attackStrength() - secondH.defend());
			firstH -= (secondH.attackStrength() - firstH.defend());
			round++;
		}
		std::cout << "Super Fight! " << firstH << " vs " << secondH << " : Winner is ";
		if (!secondH.isAlive()) {
			std::cout << firstH;
			std::cout << " in " << round << " rounds." << std::endl;
			return first;
		}
		else {
			std::cout << secondH;
			std::cout << " in " << round << " rounds." << std::endl;
			return second;
		}
	}
}