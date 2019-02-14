/*
 * linkedlist.cpp
 *
 *  Created on: Sep 21, 2018
 *      Author: vydoan
 */
#include <iostream>
#include <new>
using namespace std;

struct Node {
	int value;
	Node* next;
};

bool isFull(Node*);
bool isEmpty(Node*);
void append(Node*&, int);
void insert(Node*&, int);
bool find(Node*, int);
void remove(Node*&, int);
void clear(Node*&);
void print(Node* head);


int main() {
	Node* head = nullptr;
	cout << isEmpty(head) << endl;

	append(head, 6);
	append(head, 10);
	append(head, 12);
	insert(head, 5);
	insert(head, 1);

	print(head);

	remove(head, 5);
	print(head);

	remove(head, 1);
	print(head);

	clear(head);
	cout << isEmpty(head) << endl;
	return 0;
}

bool isFull(Node* head) {
	try {
		Node* n = new Node;
		delete n;
		return false;

	} catch (bad_alloc&) {
		return true;
	}
}

bool isEmpty(Node* head) {
	return (head == nullptr);
}

// append value to the end of list
void append(Node*& head, int value) {
	if(isFull(head)) return;

	Node* n = new Node;
	n->value = value;
	n->next = nullptr;

	if(head == nullptr) {
		head = n;
	} else {
		Node* temp = head;
		while(temp->next != nullptr) {
			temp = temp-> next;
		}
		temp->next = n;
	}
}

// insert value in ascending order
void insert(Node*& head, int k) {
	if(isFull(head)) return;

	Node* n = new Node;
	n->value = k;
	n->next = nullptr;

	if(head == nullptr) {
		head = n;
	} else {
		Node* temp = head;
		Node* prev = nullptr;
		while (temp != nullptr && k > temp->value) {
			prev = temp;
			temp = temp->next;
		}

		if(prev == nullptr) {
			n->next = head;
			head = n;
		} else {
			prev->next = n;
			n->next = temp;
		}
	}
}

bool find(Node* head, int k) {
	Node* temp = head;
	while(temp != nullptr) {
		if(temp->value == k) return true;
		temp = temp->next;
	}
	return false;
}

void remove(Node*& head, int k) {
	Node* temp = head;
	Node* prev = nullptr;

	while(temp != nullptr && temp->value != k) {
		prev = temp;
		temp = temp->next;
	}

	if(temp != nullptr) {
		if(prev == nullptr) {
			head = head->next;
		} else {
			prev->next = temp->next;
		}
		delete temp;
	}
}

void clear(Node*& head) {
	Node* temp;
	while(head != nullptr) {
		temp = head;
		head = head->next;
		delete temp;
	}
}

void print(Node* head) {
	Node* temp = head;
	while(temp != nullptr) {
			cout << temp->value << " ";
			temp = temp->next;
	}
	cout << endl;
}



