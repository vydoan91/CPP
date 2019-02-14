/*
 * queue.cpp
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

void enqueue(Node*&, Node*&, int);
void dequeue(Node*&, Node*&);
int peek(Node*);
void print(Node*);
void clear(Node*&, Node*&);

int main() {
	Node* front = nullptr;
	Node* back = nullptr;
	enqueue(front, back, 5);
	enqueue(front, back, 3);
	enqueue(front, back, 10);
	enqueue(front, back, 7);
	enqueue(front, back, 2);

	print(front);
	cout << front->value << endl;
	cout << back->value << endl;


	dequeue(front, back);
	dequeue(front, back);
	print(front);

	cout << peek(front) << endl;
	cout << front->value << endl;
	cout << back->value << endl;

	clear(front, back);
	print(front);
	return 0;
}

void enqueue(Node*& front, Node*& back, int a) {
	Node* n = new Node;
	n->value = a;
	n->next = nullptr;

	if(front == nullptr) {
		back = front = n;
	} else {
		back->next = n;
		back = n;
	}
}
void dequeue(Node*& front, Node*& back) {
	if(front != nullptr) {
		Node* temp = front;
		front = front->next;
		if(front == nullptr) back = nullptr;
		delete temp;
	}
}

int peek(Node* front) {
	if(front != nullptr) return front->value;
	return -1;
}

void print(Node* front) {
	Node* temp = front;
	while(temp != nullptr) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

void clear(Node*& front, Node*& back) {
	while(front != nullptr) {
		Node* temp = front;
		front = front->next;
		delete temp;
	}
	back = nullptr;
}



