// Name: Angadpreet Baidwan
// Student Number: 135421170
// Seneca Email: abaidwan1@myseneca.ca
// Date: 2018-07-10

#ifndef CONTACT_H
#define CONTACT_H

namespace sict {
	const int SIZE = 20;
	class Contact {
		char name[SIZE];
		long long* phone;
		int num;
	public:
		Contact();
		Contact(const char*, const long long*, int);
		~Contact();
		bool isEmpty() const;
		void display() const;
		bool isValidNum(long long) const;
		Contact(const Contact&);
		Contact& operator=(const Contact&);
		void Copy(const Contact&);
		Contact& operator+=(const long long&);
	};
}

#endif