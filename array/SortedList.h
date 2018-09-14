/*
 * SortedList.h
 *
 *  Created on: Sep 11, 2018
 *      Author: vydoan
 */

#ifndef SORTEDLIST_H_
#define SORTEDLIST_H_

#include <iostream>
using namespace std;

class SortedList {
private:
	int *list, max, size;

public:
	SortedList(int);
	void insert(int);
	void remove(int);
	void print();
};

SortedList::SortedList(int m) {
	list = new int[m];
	max = m;
	size = 0;
}

void SortedList::insert(int value) {
	if(size < max) {
		int i = 0;
		while(i < size && value > list[i]){
			i++;
		}
		int j = size;
		while(j > i) {
			list[j] = list[j - 1];
			j--;
		}
		list[i] = value;
		size++;
	}
}

void SortedList::remove(int index) {
	if(index >= 0 && index < size) {
		for (int i = index; i < size - 1; i++) {
			list[i] = list[i+1];
		}
		size--;
	}
}

void SortedList::print() {
	for(int i = 0; i < size; i++) {
		cout << list[i] << " ";
	}
	cout << endl;
}


#endif /* SORTEDLIST_H_ */
