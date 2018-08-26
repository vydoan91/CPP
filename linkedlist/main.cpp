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

	list.remove(5);
	list.remove(10);
	list.remove(7);
	list.append(399);
	list.print();

	list.clear();

	return 0;
}