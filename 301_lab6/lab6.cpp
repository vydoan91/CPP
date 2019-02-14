/*
 * lab6.cpp
 *
 *  Created on: Oct 4, 2018
 *      Author: vydoan
 */

// print doubly linked list in reverse order
#include <iostream>
using namespace std;

struct Node {
	int value;
	Node *next, *prev;
};

bool isFull();
void append(Node*&, Node*&, int);
void printFromHead(Node*);
void printFromTail(Node*);

int main() {
	// create doubly linked list
	Node* head = nullptr;
	Node* tail = head;
	append(head, tail, 6);
	append(head, tail, 8);
	append(head, tail, 9);
	append(head, tail, 1);
	cout << "head is " << head->value << endl;
	cout << "tail is " << tail->value << endl;

	// print linked list from head to tail
	printFromHead(head);
	// print linked list from tail to head
	printFromTail(tail);
	return 0;
}

bool isFull() {
	Node* n = new Node;
	if (n == nullptr) {
		return true;
	}
	delete n;
	return false;
}

// append to end of list
void append(Node*& head, Node*& tail, int value) {
	if (!isFull()) {
		Node* n = new Node;
		n->value = value;
		n->next = nullptr;
		n->prev = nullptr;

		if (head == nullptr) {
			head = tail = n;
		} else {
			tail->next = n;
			n->prev = tail;
			tail = n;
		}
	}
}

// function to print from head to tail
void printFromHead(Node* head) {
	Node* temp = head;
	while(temp != nullptr) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

// function to print from tail to head
void printFromTail(Node* tail) {
	Node* temp = tail;
	while(temp != nullptr) {
		cout << temp->value << " ";
		temp = temp->prev;
	}
	cout << endl;
}


