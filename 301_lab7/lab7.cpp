/*
 * lab7.cpp
 *
 *  Created on: Oct 11, 2018
 *      Author: vydoan
 */

#include <iostream>
using namespace std;

struct Node {
	int value;
	Node *next, *prev;
};

bool isFull();
void print(Node*);
void printOdd(Node*);
void insert(Node*&, Node*&, int);

int main() {
	// Create a doubly linked list
	Node* head = nullptr;
	Node* tail = nullptr;
	// Insert 5 values using insert function
	insert(head,tail,5);
	insert(head,tail,1);
	insert(head,tail,10);
	insert(head,tail,4);
	insert(head,tail,7);

	cout << "Doubly linked list: ";
	print(head);

	// print odd values present in DLL
	cout << "Odd values in doubly linked list: ";
	printOdd(head);
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

void print(Node* head) {
	Node* temp = head;
	while (temp != nullptr) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

void printOdd(Node* head) {
	Node* temp = head;
	while (temp != nullptr) {
		if(temp->value % 2 != 0)
			cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

void insert(Node*& head, Node*& tail, int v) {
	if (!isFull()) {
		Node* n = new Node;
		n->value = v;
		n->next = nullptr;
		n->prev = nullptr;

		if (head == nullptr) {
			head = n;
			tail = n;
		} else {
			Node* temp = head;
			Node* previous = nullptr;
			while (temp != nullptr && temp->value < v) {
				previous = temp;
				temp = temp->next;
			}

			if (previous == nullptr) {
				head = n;
			} else {
				previous->next = n;
			}

			if (temp == nullptr) {
				tail = n;
			} else {
				temp->prev = n;
			}

			n->prev = previous;
			n->next = temp;
		}
	}
}

