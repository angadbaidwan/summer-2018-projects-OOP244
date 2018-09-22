// Angadpreet Baidwan
// Student Number: 135421170
// Section: B
// Lab 4: Bitstuffing

#include <iostream>
using namespace std;

int main() {
	const int SIZE1 = 15, SIZE2 = 33;
	int array1[] = { 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0 };
	int array2[SIZE2 - 16];
	int array3[SIZE2];
	int counter = 0, k = 0;
	for (int i = 0; i < SIZE1; i++) {
		cout << array1[i] << " ";
	}
	cout << "-- " << SIZE1 << " characters" << endl;
	for (int i = 0; i < SIZE1; i++) {
		if (array1[i] == 1) {
			counter++;
		}
		else {
			counter = 0;
		}
		array2[k] = array1[i];
		if (counter == 5) {
			k++;
			array2[k] = 0;
			counter = 0;
		}
		k++;
	}
	for (int i = 0; i < (SIZE2 - 16); i++) {
		cout << array2[i] << " ";
	}
	cout << "-- " << (SIZE2 - 16) << " characters" << endl;
	counter = 0, k = 0;
	int j = 0;
	for (int i = 0; i < SIZE2; i++) {
		if (k < 8 || k > 24) {
			if (k == 0 || k == 7 || k == 25 || k == 32) {
				array3[k] = 0;
			}
			else {
				array3[k] = 1;
			}
			k++;
		}
		else {
			array3[k] = array2[j];
			j++;
			k++;
		}
	}
	for (int i = 0; i < SIZE2; i++) {
		cout << array3[i] << " ";
	}
	cout << endl;
	getchar();
	return 0;
}