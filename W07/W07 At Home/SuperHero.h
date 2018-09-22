// Student Number: 135421170
// Seneca Email: abaidwan1@myseneca.ca
// Date: 2018-07-17

#ifndef SUPERHERO_H
#define SUPERHERO_H

#include "Hero.h"

namespace sict {
	class SuperHero : public Hero {
		int s_atk;
		int s_def;
	public:
		SuperHero();
		SuperHero(const char* _name, const int _hp, const int _str, const int s_atk, const int s_def);
		int attackStrength() const;
		int defend() const;
	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif