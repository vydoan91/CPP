/*
 * main.cpp
 *
 *  Created on: Sep 27, 2018
 *      Author: vydoan
 */

#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* next;
};

void push(Node*&, int);
void print(Node*);
void printDivisible10(Node*);

int main() {
	// create pointer based stack of any number of elements
	// execute push function for any value v
	Node* top = nullptr;
	push(top, 20);
	push(top, 8);
	push(top, 6);
	push(top, 30);
	push(top, 100);
	// print all elements in stack
	print(top);

	// print all numbers in stack, divisible by 10.
	printDivisible10(top);
	return 0;
}

void push(Node*& top, int a) {
	Node* n = new Node;
	n->value = a;
	n->next = top;
	top = n;
}

void print(Node* top) {
	Node* temp = top;
	while (temp != nullptr) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

void printDivisible10(Node *top) {
	Node* temp = top;
	while (temp != nullptr) {
		if (temp->value % 10 == 0) {
			cout << temp->value << " ";
		}
		temp = temp->next;
	}
	cout << endl;
}

