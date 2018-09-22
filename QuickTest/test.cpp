#include <iostream>
using namespace std;

// SIN card number validation: Result should match last digit of sin
int main() {
	int sin = 193456787;
	int num = sin / 10;
	int tmp, tmpSum;
	int sum = 0;
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			if (((num % 10) * 2) > 9) {
				tmp = (num % 10) * 2;
				tmpSum = (tmp / 10) % 10 + tmp % 10;
				sum = sum + tmpSum;
			}
			else {
				sum = sum + (num % 10) * 2;
			}
		}
		else {
			sum = sum + num % 10;
		}
		num = num / 10;
	}
	int diff;
	if (sum % 10 != 0) {
		diff = 10 - sum % 10;
	}
	else {
		diff = 0;
	}
	cout << diff;
	getchar();
	return 0;
}