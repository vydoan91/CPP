/*
 * main.cpp
 *
 *  Created on: Oct 6, 2018
 *      Author: vydoan
 */

#include "MyDLL.h"

int main() {
	MyDLL list;
	list.append(4);
	list.append(2);
	list.append(10);
	list.append(5);

	list.print();
	list.reverse();

	list.remove(5);
	list.print();

	cout << list.find(0) << endl;
	list.clear();
	list.print();
	return 0;
}


