/*
 * queue.cpp
 *
 *  Created on: Sep 23, 2018
 *      Author: vydoan
 */


#include <iostream>
using namespace std;

bool isFull(int*, int, int, int);
bool isEmpty(int*, int, int);
void enqueue(int*, int&, int&, int, int);
void dequeue(int*, int&, int&, int);
int first(int*, int, int);
void print(int*, int, int, int);

int main() {
	int front = 0;
	int back = 0;
	int max = 5;
	int list [max];
	enqueue(list, front, back, max, 4);
	enqueue(list, front, back, max, 10);
	enqueue(list, front, back, max, 2);
	enqueue(list, front, back, max, 6);
	enqueue(list, front, back, max, 5);
	enqueue(list, front, back, max, 7);

	print(list, front, back, max);

	dequeue(list, front, back, max);
	dequeue(list, front, back, max);

	print(list, front, back, max);

	enqueue(list, front, back, max, 8);
	enqueue(list, front, back, max, 5);

	print(list, front, back, max);
	cout << "front is " << front << endl;
	cout << "back is " << back << endl;
	return 0;
}

bool isFull(int* list, int front, int back, int max) {
	return (front == ((back + 1) % max));
}

bool isEmpty(int* list, int front, int back) {
	return (front == back);
}
void enqueue(int* list, int& front, int& back, int max, int a) {
	if(!isFull(list, front, back, max)) {
		list[back] = a;
		back = (back + 1) % max;
	}
}

void dequeue(int* list, int& front, int& back, int max) {
	if(!isEmpty(list, front, back)) {
		front = (front + 1) % max;
	}
}

// return first value in queue
int first(int* list, int front, int back ) {
	if(!isEmpty(list, front, back)) return list[front];
	return -1;
}
void print(int* list, int front, int back, int max) {
	if(!isEmpty(list, front, back)) {
		int i = front;
		while(i != back) {
			cout << list[i] << " ";
			i = (i + 1) % max;
		}
		cout << endl;
	}
}




