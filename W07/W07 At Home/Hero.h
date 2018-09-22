// Name: Angadpreet Baidwan
// Student Number: 135421170
// Seneca Email: abaidwan1@myseneca.ca
// Date: 2018-07-17

#ifndef HERO_H
#define HERO_H

#include <iostream>

namespace sict {
	const int max_rounds = 100;
	const int size = 40;
	class Hero {
		char name[size + 1];
		int hp;
		int str;
	public:
		Hero();
		Hero(const char* _name, const int _hp, const int _str);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		bool isEmpty() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};
	const Hero& operator*(const Hero& first, const Hero& second);
}

#endif
