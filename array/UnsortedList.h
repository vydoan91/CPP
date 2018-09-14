/*
 * UnsortedList.h
 *
 *  Created on: Sep 11, 2018
 *      Author: vydoan
 */

#ifndef UNSORTEDLIST_H_
#define UNSORTEDLIST_H_

#include <iostream>
using namespace std;

class UnsortedList {
private:
	 int *list, size, max;
public:
	 UnsortedList(int);
	 bool isFull();
	 bool isEmpty();
	 void insert(int);
	 int find(int);
	 void removeAtIndex(int);
	 void removeValue(int);
	 void removeLast(int);
	 int get(int);
	 void print();
};

UnsortedList::UnsortedList(int m) {
	max = m;
	list = new int[max];
	size = 0;
}

bool UnsortedList::isFull() {
	if(size == max)
		return true;
	else
		return false;
}

bool UnsortedList::isEmpty() {
	if (size == 0)
		return true;
	else
		return false;
}

// Adds a to the end of the list
void UnsortedList::insert(int value) {
	if(size < max) {
		list[size] = value;
		size++;
	}
}

// Searches the list for a.
// Returns the index of the element where it's found, -1 otherwise
int UnsortedList::find(int value) {
	for(int i = 0; i < size; i++) {
		if(list[i] == value) return i;
	}
	return -1;
}

// version 1:
// removes the item at position a within the list
// requires shifting of all items one position to the left,
// overwriting the item
void UnsortedList::removeAtIndex(int index) {
	if(index >= 0 && index < size) {
		int i = index;
		size--;
		while(i < size) {
			list[i] = list[i + 1];
			i++;
		}
	}
}

// version 2:
// if item a is found in the list, it's removed
// by shifting
void UnsortedList::removeValue(int value) {
	int i = find(value);
	if(i != -1) {
		removeAtIndex(i);
	}
}

// version 3:  a constant time remove
void UnsortedList::removeLast(int index) {
	if(index >= 0 && index < size) {
		list[index] = list[size - 1];
		size--;
	}
}

int UnsortedList::get(int index) {
	if(index <= 0 && index < size) {
		return list[index];
	}
	return -1;
}

void UnsortedList::print() {
	for(int i = 0; i < size; i++) {
		cout << list[i] << " ";
	}
	cout << endl;
}

#endif /* UNSORTEDLIST_H_ */
