/*
 * main.cpp
 *
 *  Created on: Sep 14, 2018
 *      Author: vydoan
 */

#include "MyQueue.h"
int main() {
	MyQueue queue(5);

	queue.enqueue(4);
	queue.enqueue(2);
	queue.enqueue(1);
	queue.enqueue(10);
	queue.print();

	queue.dequeue();
	queue.dequeue();

	queue.print();
	queue.enqueue(0);
	queue.print();

	queue.dequeue();
	queue.print();
}



