/*
 * stack.cpp
 *
 *  Created on: Sep 23, 2018
 *      Author: vydoan
 */

#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* next;
};

void push(Node*&, int);
void pop(Node*&);
int peek(Node*);
void print(Node*);
void clear(Node*&);

int main() {
	Node* top = nullptr;

	push(top, 3);
	push(top, 9);
	push(top, 6);
	push(top, 2);
	push(top, 7);
	print(top);

	pop(top);
	pop(top);
	print(top);

	cout << peek(top) << endl;

	clear(top);
	return 0;
}

void push(Node*& top, int a) {
	Node* n = new Node;
	n->value = a;
	n->next = top;
	top = n;
}

void pop(Node*& top) {
	if(top != nullptr) {
		Node* temp = top;
		top = top->next;
		delete temp;
	}
}

int peek(Node* top) {
	if(top != nullptr) return top->value;
}

void print(Node* top) {
	Node* temp = top;
	while(temp != nullptr) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

void clear(Node*& top) {
	while(top != nullptr) {
		Node* temp = top;
		top = top->next;
		delete temp;
	}
}


