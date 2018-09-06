// HW1 - CS301
// Student: Vy Doan

#ifndef MYLIST_H_
#define MYLIST_H_

#include <new>
using namespace std;

// A class implements a linked list
class MyList {

private:
	// Node is a nested struct storing value of type int and next of type Node*
	struct Node {
		int value;
		Node* next;
	};
	// The head pointer - stores the memory address of the first node in the list.
	Node* head;

public:
	MyList();
	~MyList();
	int getHead() const;

	bool isFull() const;
	bool isEmpty() const;
	bool find(int) const;
	int remove(int);
	int append(int);
	void clear();
	void print() const;
};

// Constructor - initializes head to null
MyList::MyList() {
	head = nullptr;
}

// Destructor - frees all memory used by the list by calling clear method
MyList::~MyList() {
	clear();
}

int MyList::getHead() const {
	return head->value;
}
// isFull - returns true if there's NOT enough memory to create a new node, false otherwise.
bool MyList::isFull() const {
	try {
		Node* n = new Node;
		delete n;
		return false;
	} catch(bad_alloc&) {
		return true;
	}
}

// isEmpty - returns true if the list is empty, false otherwise.
bool MyList::isEmpty() const {
	if(head == nullptr) {
		return true;
	} else {
		return false;
	}
}

// find - searches the list for it's argument.
// Returns true if it's found, false otherwise.
bool MyList::find(int k) const {
	Node* temp;
	temp = head;

	while(temp != nullptr) {
		if(temp->value == k) {
			return true;
		}
		temp = temp->next;
	}

	return false;
}

// remove - removes the first node found matching the argument passed to remove.
// Returns 0 if a node is removed, -1 otherwise.
int MyList::remove(int k) {
	Node *temp, *prev;
	temp = head;
	prev = nullptr;

	// Search for node to be deleted
	while(temp != nullptr && temp->value != k) {
		prev = temp;
		temp = temp->next;
	}

	// if temp != null, node is found
	if(temp != nullptr) {
		// if prev == nullptr, meaning that desired node is the first node
		if(prev == nullptr) {
			head = head->next;
		// else, node is in the middle or end of the list
		} else {
			prev->next = temp->next;
		}
		return 0;
	}
	// if temp == null, desired node in not in the list, return -1
	return -1;
}

// append - attempts to append it's argument to the list in a new node.
// Returns 0 if successful, -1 otherwise.
int MyList::append(int v) {

	// if list is full, return -1
	if(isFull()) {
		return -1;
	}

	// Create the new node with provided value
	Node* n = new Node;
	n->value = v;
	n->next = nullptr;

	// if empty, the new node becomes head
	if(isEmpty()) {
		head = n;
	// else, add node to end of list
	} else {
		Node* temp;
		temp = head;
		while(temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = n;
	}

	return 0;
}

// clear - frees all memory used by the linked list, leaving head set to null.
void MyList::clear() {
	while (head != nullptr) {
		Node* p = head;
		head = head->next;
		delete p;
	}
}

// print - displays the contents of the list to the screen.
void MyList::print() const {
	Node* temp;
	temp = head;

	if(head == nullptr) {
		cout << "List is empty" << endl;
	}
	while(temp != nullptr) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << "\n";
}

#endif /* MYLIST_H_ */
