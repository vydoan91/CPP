/*
 * main.cpp
 *
 *  Created on: Sep 20, 2018
 *      Author: vydoan
 */

#include <iostream>
using namespace std;

class MyStack {

private:
	int *list, top, max;

public:
	MyStack(int);
	int push(int);
	int getTop();
	int getValueAtPosition(int);
	void print();
};

// Constructor - Initializes max with
// the argument and then dynamically allocates
// a new array of max elements, storing it's
// address in list.  Initializes top to -1.
MyStack::MyStack(int m) {
	max = m;
	list = new int[max];
	top = -1;
}

// push - pushes it's argument onto the stack.
// Returns 0 if successful, -1 otherwise.
int MyStack::push(int value) {
	if(top < max - 1) {
		top++;
		list[top] = value;
		return 0;
	}
	return -1;
}

// getTop - return the top element
int MyStack::getTop() {
	return list[top];
}

// getValueAtPosition - return value of element at position index
int MyStack::getValueAtPosition(int index) {
	return list[index];
}

// print the stack
void MyStack::print() {
	if(top > -1) {
		for(int i = 0; i <= top; i++) {
			cout << list[i] << " ";
		}
		cout << endl;
	}
}

int main() {

	// 1. Create a stack
	MyStack stack(5);
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.print();

	// 2. extract top element
	int topElement = stack.getTop();
	cout << "Top element is " << topElement << endl;

	// 3. add top/highest element with 2nd element of stack
	int secondElement = stack.getValueAtPosition(1);
	int result = topElement + secondElement;

	// 4. print the result
	cout << "Sum of top and 2nd element is " << result << endl;
	return 0;
}


