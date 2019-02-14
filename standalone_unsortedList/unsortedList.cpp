/*
 * unsortedList.cpp
 *
 *  Created on: Sep 22, 2018
 *      Author: vydoan
 */

#include <iostream>
using namespace std;

// isFull - determines if the list is full
bool isFull(int* list, int size, int max) {
	return (size == max);
}

// isEmpty - determines if the list is empty
bool isEmpty(int* list, int size) {
	return (size == 0);
}

// insert - adds a value to the end of the list
void insert(int* list, int max, int& size, int a) {
	if(size < max) {
		list[size] = a;
		size++;
	}
}

// Searches the list for a.
// Returns the index of the element where it's found, -1 otherwise
int find(int* list, int size, int a) {
	for(int i = 0; i < size; i++) {
		if(list[i] == a) return i;
	}
	return -1;
}

// version 1:
// removes the item at position a within the list
// requires shifting of all items one position to the left,
// overwriting the item
void removeAtIndex(int* list, int& size, int index) {
	if(index >= 0 && index < size) {
		for(int i = index; i < size - 1; i++) {
			list[i] = list[i+1];
		}
		size--;
	}
}

// version 2:
// if item a is found in the list, it's removed
// by shifting as above.
void removeValue(int* list, int& size, int a) {
	int i = find(list, size, a);
	removeAtIndex(list, size, i);
}

// version 3:  a constant time remove
void remove(int* list, int& size, int index) {
	if(index >= 0 && index < size) {
		list[index] = list[size - 1];
		size--;
	}
}

// get - retrieve an item from position a within the list
int get(int* list, int size, int index) {
	if(index >= 0 && index < size) return list[index];
	return -1;
}

void print(int* list, int size) {
	for(int i = 0; i < size; i++) {
		cout << list[i] << " ";
	}
	cout << endl;
}

int main() {
	int max = 5;
	int size = 0;
	int list [max];
	insert(list, max, size, 9);
	insert(list, max, size, 7);
	insert(list, max, size, 6);
	insert(list, max, size, 10);
	print(list, size);

	remove(list, size, 0);
	print(list, size);

	cout << size << endl;

	return 0;
}


