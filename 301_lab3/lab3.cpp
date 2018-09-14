/*
 * 301_lab3.cpp
 *
 *  Created on: Sep 13, 2018
 *      Author: vydoan
 */


#include <iostream>
using namespace std;

class Array {
private:
	 int *list, size, max;
public:
	 Array(int);
	 void insert(int);
	 int find(int);
	 void removeAtIndex(int);
	 void print();
};

Array::Array(int m) {
	max = m;
	list = new int[max];
	size = 0;
}

// Adds a to the end of the list
void Array::insert(int value) {
	if(size < max) {
		list[size] = value;
		size++;
	}
}

// Searches the list for a.
// Returns the index of the element where it's found, -1 otherwise
int Array::find(int value) {
	for(int i = 0; i < size; i++) {
		if(list[i] == value) return i;
	}
	return -1;
}

// removes the item at position a within the list
// requires shifting of all items one position to the left,
// overwriting the item
void Array::removeAtIndex(int index) {
	if(index >= 0 && index < size) {
		int i = index;
		size--;
		while(i < size) {
			list[i] = list[i + 1];
			i++;
		}
	}
}

void Array::print() {
	for(int i = 0; i < size; i++) {
		cout << list[i] << " ";
	}
	cout << endl;
}

int main() {
	// User is looking for element with value 9
	int userValue = 3;

	Array array(5);
	array.insert(4);
	array.insert(7);
	array.insert(2);
	array.insert(9);
	array.insert(3);
	array.print();

	// Find location of an element provided by an user, in an array.
	int indexFound = array.find(userValue);
	cout << "Location of user's element is " << indexFound << endl;

	// Remove element which is present 2 locations ahead of it.
	array.removeAtIndex(indexFound - 2);

	array.print();

}
