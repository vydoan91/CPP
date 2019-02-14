/*
 * MyQueue.h
 *
 *  Created on: Sep 14, 2018
 *      Author: vydoan
 */

#ifndef MYQUEUE_H_
#define MYQUEUE_H_

#include <iostream>
using namespace std;

class MyQueue {
private:
	int *list, front, back, max;
public:
	MyQueue(int);
	~MyQueue();
	int enqueue(int);
	int dequeue();
	int first(int&);
	void print();
};

MyQueue::MyQueue(int m) {
	max = m;
	list = new int[max];
	front = back = 0;
}

MyQueue::~MyQueue() {
	delete[] list;
}

// enqueue - Accepts an integer as it's only argument.
// Adds the argument to the back of the queue.
// Returns 0 if successful, -1 otherwise.  Fails if the queue was full.
int MyQueue::enqueue(int value) {
	if(front != (back + 1) % max) {
		list[back] = value;
		back = (back + 1) % max;
		return 0;
	}
	return -1;
}

// dequeue - Removes the value at the front of the queue.
// Returns 0 if successful, -1 otherwise.
// Fails if the queue was empty.
int MyQueue::dequeue() {
	if(front != back) {
		front = (front + 1) % max;
		return 0;
	}
	return -1;
}

// first - assigns the value at the front of the
// queue to it's reference parameter.
// Returns 0 if successful, -1 otherwise.
// Fails if the queue was empty.  Assigns nothing
// to the reference parameter if the queue is empty.
int MyQueue::first(int& a) {
	if(front != back) {
		a = front;
		return 0;
	}
	return -1;
}

void MyQueue::print() {
	int i = front;
	while (i != back) {
		cout << list[i] << " ";
		i = (i + 1) % max;
	}
	cout << endl;
}

#endif /* MYQUEUE_H_ */
