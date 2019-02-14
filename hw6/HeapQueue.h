//
// Created by VY DOAN on 11/16/18.
//

#ifndef HW6_HEAPQUEUE_H
#define HW6_HEAPQUEUE_H

//testing
#include "iostream"
using namespace std;
//testing

class HeapQueue {
private:
    //heap - a pointer that holds a dynamically allocated array of integers.
    //size - stores the size of the array.
    //bottom - keeps track of the bottom of the heap.
    int *heap, size, bottom;

    void swap(int&, int&);

    void ReHeapUp();

    void ReHeapDown();

public:
    HeapQueue(int);

    ~HeapQueue();

    void enqueue(int);

    void dequeue();

    int top() const;

    //testing
    void print();
};


// constructor - accepts an integer as it's only argument and dynamically
// allocates an array with that many elements, stores the argument in size,
// and initializes bottom to -1.  Address of the new array is stored in heap.
HeapQueue::HeapQueue(int s) {
    size = s;
    bottom = -1;
    heap = new int[size];
}

//destructor - deallocates the array
HeapQueue::~HeapQueue() {
    delete[] heap;
}

// enqueue - if there's enough free space in the heap, adds it's argument to the heap.
// Throws an exception otherwise.
void HeapQueue::enqueue(int i) {
    if (bottom != size) {
        bottom++;
        heap[bottom] = i;
        ReHeapUp();
    } else {
        throw "Heap is full";
    }
}

// dequeue - if the heap isn't empty, removes the top of the heap from the heap.
// Throws an exception otherwise.
void HeapQueue::dequeue() {
    if (bottom != -1) {
        swap(heap[0], heap[bottom]);
        bottom--;
        ReHeapDown();
    } else {
        throw "Heap is empty";
    }
}

//top - returns a copy of the value on the top of the heap,
// doesn't change the heap in any way.  Throws an exception if the heap is empty.
int HeapQueue::top() const {
    if (bottom == -1) {
        throw "Heap is empty";
    }
    return heap[0];
}

//ReHeapUp - called by enqueue to rebuild the heap.
void HeapQueue::ReHeapUp() {
    int i = bottom;
    while (i != 0) {
        int p = (i - 1) / 2;
        if (heap[i] > heap[p]) {
            swap(heap[i], heap[p]);
        }
        i = p;
    }
}

//ReHeapDown - called by dequeue to rebuild the heap.
void HeapQueue::ReHeapDown() {
    int p = 0;
    int bc;
    while (p < bottom) {
        int lc = p * 2 + 1;
        int rc = p * 2 + 2;
        if(lc <= bottom) {
            if (lc == bottom) { // if current parent has only 1 child (left child)
                bc = lc;
            } else { // else, parent has 2 children
                bc = (heap[lc] > heap[rc]) ? lc : rc;
            }
        } else {
            return;
        }

        if (heap[p] < heap[bc]) {
            swap(heap[bc], heap[p]);
            p = bc;
        } else {
            return;
        }
    }
}

// swap values of elements provided in the arguments
void HeapQueue::swap(int &e1, int &e2) {
    int temp = e1;
    e1 = e2;
    e2 = temp;
}

// testing
void HeapQueue::print() {
    for(int i = 0; i <= bottom; i++) {
        cout << heap[i] << "\t";
    }
    cout << endl;
}

#endif //HW6_HEAPQUEUE_H
