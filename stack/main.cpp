/*
 * main.cpp
 *
 *  Created on: Sep 13, 2018
 *      Author: vydoan
 */

#include "MyStack.h"

int main() {
	int a;
	MyStack stack(5);
	stack.push(4);
	stack.push(1);
	stack.push(10);
	stack.push(2);
	stack.push(8);
	stack.push(7);
	stack.print();
	stack.pop();
	stack.pop();
	stack.print();

	stack.peek(a);
	cout << a << endl;
}


