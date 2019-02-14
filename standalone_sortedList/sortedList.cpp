/*
 * sortedList.cpp
 *
 *  Created on: Sep 22, 2018
 *      Author: vydoan
 */

#include <iostream>
using namespace std;

void insert(int*, int, int&, int);
void remove(int*, int&, int);
void print(int*, int);

int main() {
	int size = 0;
	int max = 5;
	int list [max];
	insert(list, max, size, 8);
	insert(list, max, size, 2);
	insert(list, max, size, 10);
	insert(list, max, size, 9);
	insert(list, max, size, 3);
	insert(list, max, size, 6);

	print(list, size);

	remove(list, size, 2);
	print(list, size);

	cout << "size is " << size << endl;

	return 0;
}

void insert(int* list, int max, int& size, int a) {
	if(size < max) {
		int index = 0;
		while(index < size && a > list[index]) {
			index++;
		}
		for(int i = size; i > index; i--) {
			list[i] = list[i-1];
		}
		list[index] = a;
		size++;
	}
}

// for this algorithm, let a be the index of the element containing
// the value we want to remove
void remove(int* list, int& size, int index) {
	if(index >=0 && index < size) {
		for(int i = index; i < size - 1; i++) {
			list[i] = list[i + 1];
		}
		size--;
	}
}

void print(int* list, int size) {
	for(int i = 0; i < size; i++) {
		cout << list[i] << " ";
	}
	cout << endl;
}





