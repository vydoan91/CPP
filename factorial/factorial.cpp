/*
 * factorial.cpp
 *
 *  Created on: Oct 19, 2018
 *      Author: vydoan
 */

#include <iostream>
using namespace std;

int factorial(int);

int main() {
	int a = 5;
	cout << a << "! = " << factorial(a) << endl;
	return 0;
}

int factorial(int a) {
	if(a <= 1) {
		return 1;
	}
	return a * factorial(a-1);
}



