/*
 * circularLinkedList.cpp
 *
 *  Created on: Oct 25, 2018
 *      Author: vydoan
 */
#include <iostream>
using namespace std;
struct Node {
	int v;
	Node* next;
};

bool isFull() {
	Node* n = new Node;
	if(n == nullptr)
		return true;
	delete n;
	return false;
}

void append(Node*& tail, int k) {
	if(!isFull()) {
		Node* n = new Node;
		n->v = k;
		n->next = nullptr;

		if(tail == nullptr) {
			tail = n;
			tail->next = tail;
		} else {
			n->next = tail->next;
			tail->next = n;
			tail = n;
		}
	}
}

void insert(Node*& tail, int k) {
	if(!isFull()) {
		Node* n = new Node;
		n->v = k;
		n->next = nullptr;

		if(tail == nullptr) {
			tail = n;
			tail->next = tail;
		} else {
			Node* temp = tail->next;
			Node* prev = nullptr;

			do {
				if(k < temp->v)
					break;
				prev = temp;
				temp = temp->next;
			} while(temp != tail->next);

			n->next = temp;

			if(prev == nullptr) {
				tail->next = n;
			} else {
				prev->next = n;
				if(temp == tail->next) {
					tail = n;
				}
			}
		}
	}
}

void remove(Node*& tail, int k) {
	if(tail != nullptr) {
		Node* temp = tail->next;
		Node* prev = tail;
		do {
			if(k == temp->v)
				break;
			prev = temp;
			temp = temp->next;
		} while(temp != tail->next);

		if(k == temp->v) {
			if(tail == tail->next) {
				tail = nullptr;
			} else {
				prev->next = temp->next;
				if(temp == tail)
					tail = prev;
			}
			delete temp;
		}
	}


}

bool find(Node* tail, int k) {
	if(tail != nullptr) {
		Node* temp = tail;
		do {
			if(k == temp->v)
				return true;
			temp = temp->next;
		} while(temp != tail);
	}
	return false;
}

void clear(Node* tail) {
	if(tail != nullptr) {
		Node* q = tail;
		Node* temp = nullptr;
		do {
			temp = tail;
			tail = tail->next;
			delete temp;
		} while(tail != q);
		tail = nullptr;
	}
}

void print(Node* tail) {
	if(tail != nullptr) {
		Node* temp = tail->next;
		do {
			cout << temp->v << " ";
			temp = temp->next;
		} while(temp != tail->next);
		cout << endl;
	}
}
int main() {
	Node* tail = nullptr;
	append(tail, 9);
	append(tail, 10);
	insert(tail, 4);
	insert(tail, 5);
	insert(tail, 3);
	print(tail);
	cout << tail->v << endl;

	remove(tail, 3);
	print(tail);
	cout << tail->v << endl;

	remove(tail, 10);
	print(tail);
	cout << tail->v << endl;

	cout << find(tail, 9) << endl;

	clear(tail);
	print(tail);
	return 0;
}
