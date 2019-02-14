/*
 * doublyLinkedlist.cpp
 *
 *  Created on: Oct 4, 2018
 *      Author: vydoan
 */
#include <iostream>
using namespace std;

struct Node {
	int value;
	Node *next, *prev;
};

bool isFull();
void append(Node*&, Node*&, int);
bool find(Node*, int);
void print(Node*);
void insert(Node*&, Node*&, int);
void remove(Node*&, Node*&, int);

int main() {
	Node* head = nullptr;
	Node* tail = head;
	insert(head, tail, 6);
	insert(head, tail, 8);
	insert(head, tail, 9);
	insert(head, tail, 1);
	print(head);
	cout << "head = " << head->value << endl;
	cout << "tail = " << tail->value << endl;
	cout << "head->next = " << head->next->value << endl;
	cout << "tail->prev = " << tail->prev->value << endl;

	remove(head, tail, 9);
	remove(head, tail, 1);
	print(head);
	cout << "head = " << head->value << endl;
	cout << "tail = " << tail->value << endl;
	cout << "head->next = " << head->next->value << endl;
	cout << "tail->prev = " << tail->prev->value << endl;

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

bool find(Node* head, int k) {
	Node* temp = head;
	while (temp != nullptr) {
		if (temp->value == k)
			return true;
		temp = temp->next;
	}
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

void remove(Node*& head, Node*& tail, int v) {
	Node* temp = head;
	Node* previous = nullptr;

	while (temp != nullptr && temp->value != v) {
		previous = temp;
		temp = temp->next;
	}

	if (temp != nullptr) {
		if (previous == nullptr) {
			head = head->next;
		} else {
			previous->next = temp->next;
		}

		if (temp->next != nullptr) {
			temp->next->prev = previous;
		} else {
			tail = previous;
		}
		delete temp;
	}

}

