/*
 * stack.cpp
 *
 *  Created on: Sep 22, 2018
 *      Author: vydoan
 */

#include <iostream>
using namespace std;

void push(int*, int&, int , int);
void pop(int*, int&);
int peek(int*, int);
void print(int*, int);

int main() {
	int max = 5;
	int top = -1;
	int list [max];
	push(list, top, max, 7);
	push(list, top, max, 9);
	push(list, top, max, 2);
	push(list, top, max, 0);
	push(list, top, max, 10);
	push(list, top, max, 4);
	push(list, top, max, 5);
	print(list, top);
	cout << "top is " << top << endl;

	pop(list, top);
	pop(list, top);
	print(list, top);

	cout << "top is " << top << endl;
	return 0;
}

void push(int* list, int& top, int max, int a) {
	if(top < max - 1) {
		top++;
		list[top] = a;
	}
}

void pop(int* list, int& top) {
	if(top > -1) {
		top--;
	}
}

int peek(int* list, int top) {
	if(top > -1) return list[top];
	return -1;
}

void print(int* list, int top) {
	if(top > -1) {
		for(int i = 0; i <= top; i++) {
			cout << list[i] << " ";
		}
		cout << endl;
	}
}


