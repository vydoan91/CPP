/*
 * MyList.cpp
 *
 *  Created on: Aug 24, 2018
 *      Author: vydoan
 */

#include <iostream>
#include "MyList.h"
using namespace std;

int main() {
	MyList list;

	list.append(5);
	list.append(7);
	list.append(6);
	list.append(2);
	list.append(4);
	list.append(10);
	list.print();

	cout << list.isEmpty() << endl;

	cout << list.find(30) << endl;

	cout << list.find(2) << endl;

	cout << list.remove(40) << endl;

	cout << list.remove(5) << endl;

	list.print();

	list.clear();

	list.print();

	return 0;
}
