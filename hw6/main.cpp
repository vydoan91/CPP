#include "HeapQueue.h"

int main() {
    HeapQueue heap(11);
    heap.enqueue(10);
    heap.enqueue(8);
    heap.enqueue(7);
    heap.enqueue(6);
    heap.enqueue(11);
    heap.print();
    heap.enqueue(3);
    heap.enqueue(4);
    heap.enqueue(2);
    heap.enqueue(1);
    heap.enqueue(20);
    heap.print();
    cout << heap.top() << endl;
    heap.dequeue();
    heap.print();
    cout << heap.top() << endl;
}