// Name: Angadpreet Baidwan
// Student Number: 135421170
// Seneca Email: abaidwan1@myseneca.ca
// Date: 2018-07-12

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Hero.h"
using namespace std;

namespace sict {
	Hero::Hero() {
		name[0] = '\0';
		hp = 0;
		str = 0;
	}
	Hero::Hero(const char* _name, const int _hp, const int _str) {
		if (_name[0] != '\0' && _name != nullptr && _hp > 0 && _str > 0) {
			strncpy(name, _name, size);
			name[size] = '\0';
			hp = _hp;
			str = _str;
		}
		else {
			*this = Hero();
		}
	}
	void Hero::operator-=(int attack) {
		if (attack > 0) {
			hp -= attack;
			if (hp < 0) {
				hp = 0;
			}
		}
	}
	bool Hero::isAlive() const {
		if (hp > 0) {
			return true;
		}
		else {
			return false;
		}
	}
	int Hero::attackStrength() const {
		if (!isEmpty()) {
			return str;
		}
		else {
			return 0;
		}
	}
	bool Hero::isEmpty() const {
		return (name[0] == '\0' && hp == 0 && str == 0);
	}
	ostream& operator<<(ostream& os, const Hero& hero) {
		if (!hero.isEmpty()) {
			os << hero.name;
			return os;
		}
		else {
			os << "No hero";
			return os;
		}
	}
	const Hero& operator*(const Hero& first, const Hero& second) {
		Hero firstH = first;
		Hero secondH = second;
		int round = 0;
		for (int i = 0; i < max_rounds && firstH.isAlive() && secondH.isAlive(); i++) {
			secondH -= firstH.attackStrength();
			firstH -= secondH.attackStrength();
			round++;
		}
		cout << "Ancient Battle! " << firstH << " vs " << secondH << " : Winner is ";
		if (!secondH.isAlive()) {
			cout << firstH;
			cout << " in " << round << " rounds." << endl;
			return first;
		}
		else {
			cout << secondH;
			cout << " in " << round << " rounds." << endl;
			return second;
		}
	}
}