/*
 * main.cpp
 *
 *  Created on: Sep 11, 2018
 *      Author: vydoan
 */

#include "UnsortedList.h"
#include "SortedList.h"
#include<iostream>

using namespace std;

int main() {
	UnsortedList mylist(5);
	mylist.insert(7);
	mylist.insert(2);
	mylist.insert(4);
	mylist.insert(5);
	mylist.insert(0);
	mylist.print();

	mylist.removeAtIndex(0);
	mylist.print();

	mylist.removeValue(0);
	mylist.print();

	cout << mylist.get(0) << endl;

	SortedList mySortedlist(5);
	mySortedlist.insert(7);
	mySortedlist.insert(2);
	mySortedlist.insert(4);
	mySortedlist.insert(5);
	mySortedlist.insert(0);
	mySortedlist.print();

	mySortedlist.remove(3);
	mySortedlist.print();

	return 0;
}



