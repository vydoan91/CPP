/*
 * MyDLL.h
 *
 *  Created on: Oct 6, 2018
 *      Author: vydoan
 */

#ifndef MYDLL_H_
#define MYDLL_H_

#include <iostream>
using namespace std;

class MyDLL {
private:
	struct Node {
		int data;
		Node *next, *prev;
	};
	Node *head, *tail;
public:
	MyDLL();
	~MyDLL();
	void append(int);
	void remove(int);
	bool find(int) const;
	void clear();
	void print() const;
	void reverse() const;
};

//constructor - initializes head and tail to null.
MyDLL::MyDLL() {
	head = tail = nullptr;
}

//destructor - frees all memory used by the list.
MyDLL::~MyDLL() {
	clear();
}

//append - if there is enough memory, stores it's argument
//in a new node and attaches that new node to the end of the list.
void MyDLL::append(int i) {
	Node* n = new Node;
	// if n!=nullptr, list is not full
	if (n != nullptr) {
		n->data = i;
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

//remove - searches for it's argument in the list.
//Removes the first node it finds that contains
//a value matching it's argument.
void MyDLL::remove(int i) {
	Node* temp = head;
	Node* previous = nullptr;

	while (temp != nullptr && temp->data != i) {
		previous = temp;
		temp = temp->next;
	}

	// if temp != nullptr, the desired node is found
	if (temp != nullptr) {
		// if previous is null, the desired node is the head node
		if (previous == nullptr) {
			head = head->next;
		} else {
			previous->next = temp->next;
		}

		// if temp->next is null, the deleted node is the tail node
		if(temp->next == nullptr) {
			tail = previous;
		} else {
			temp->next->prev = previous;
		}

		delete temp;
	}
}

//find - searches for it's argument in the list.
//Returns true if it's found, false otherwise.
bool MyDLL::find(int i) const {
	Node* temp = head;
	while (temp != nullptr) {
		if (temp->data == i)
			return true;
		temp = temp->next;
	}
	return false;
}

//clear - frees all memory used by the list.
//Ensures head and tail are set back to null.
void MyDLL::clear() {
	Node* temp;
	while (head != nullptr) {
		temp = head;
		head = head->next;
		delete temp;
	}
	head = tail = nullptr;
}

//print - prints the values stored in the list in order.
void MyDLL::print() const {
	Node* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

//reverse - prints the values stored in the list in reverse order.
void MyDLL::reverse() const {
	Node* temp = tail;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << endl;
}

#endif /* MYDLL_H_ */
