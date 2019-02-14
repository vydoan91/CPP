/*
 * MyStack.h
 *
 *  Created on: Sep 13, 2018
 *      Author: vydoan
 */

#ifndef MYSTACK_H_
#define MYSTACK_H_

#include <iostream>
using namespace std;

class MyStack {
private:
	int *list, top, max;

public:
	MyStack(int);
	~MyStack();
	int push(int);
	int pop();
	int peek(int&) const;
	void print();
};

// Constructor -  accepts an integer as
// it's only argument.  Initializes max with
// the argument and then dynamically allocates
// a new array of max elements, storing it's
// address in list.  Initializes top to -1.
MyStack::MyStack(int m) {
	max = m;
	list = new int[max];
	top = -1;
}

// Destructor -  frees all memory used by the MyStack object
MyStack::~MyStack() {
	delete [] list;
}

// push - pushes it's argument onto the stack.
// Returns 0 if successful, -1 otherwise.
// The push operation will fail if the stack is full.
int MyStack::push(int value) {
	if(top < max - 1) {
		top++;
		list[top] = value;
		return 0;
	}
	return -1;
}

// pop - removes the top value from the stack.
// Returns 0 if successful, -1 otherwise.  Fails if the stack is empty.
int MyStack::pop() {
	if(top > -1) {
		top--;
		return 0;
	}
	return -1;
}

// peek - assigns the top value of the stack to it's
// reference parameter if the stack is not empty.
// Assigns nothing to the reference parameter if the stack is empty.
// Returns 0 if the stack isn't empty, -1 otherwise.
int MyStack::peek(int& a) const {
	if(top > -1) {
		a = list[top];
		return 0;
	}
	return -1;
}

void MyStack::print() {
	if(top > -1) {
		for(int i = 0; i <= top; i++) {
			cout << list[i] << " ";
		}
		cout << endl;
	}
}
#endif /* MYSTACK_H_ */
