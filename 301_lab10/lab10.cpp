/*
 * lab10.cpp
 *
 *  Created on: Nov 1, 2018
 *      Author: vydoan
 */
#include <iostream>
using namespace std;

struct Node {
	int i;
	Node *left, *right;
};

int height(Node* r) {
	if (r == nullptr)
		return -1;
	int left = height(r->left);
	int right = height(r->right);
	if (left > right)
		return (1 + left);
	else
		return (1 + right);
}

int difference(Node* r) {
	return height(r->left) - height(r->right);
}

void rotateRight(Node*& r) {
	Node* temp = r->left;
	r->left = temp->right;
	temp->right = r;
	r = temp;
}

void rotateLeft(Node*& r) {
	Node* temp = r->right;
	r->right = temp->left;
	temp->left = r;
	r = temp;
}

void rotateRightLeft(Node*& r) {
	rotateRight(r->right);
	rotateLeft(r);
}

void rotateLeftRight(Node*& r) {
	rotateLeft(r->left);
	rotateRight(r);
}

void balance(Node*& r) {
	if (difference(r) == -2) {
		if (difference(r->right) == -1) {
			rotateLeft(r);
		} else {
			rotateRightLeft(r);
		}
	}

	if (difference(r) == 2) {
		if (difference(r->left) == 1) {
			rotateRight(r);
		} else {
			rotateLeftRight(r);
		}
	}
}

void insert(Node*& r, int i) {
	if (r == nullptr) {
		r = new Node;
		r->i = i;
		r->left = nullptr;
		r->right = nullptr;
	} else if (i < r->i) {
		insert(r->left, i);
	} else {
		insert(r->right, i);
	}
	balance(r);
}

void printPreorder(Node* r) {
	if (r == nullptr) {
		return;
	}
	cout << r->i << " ";
	printPreorder(r->left);
	printPreorder(r->right);
}

int main() {
	// create tree using insert
	// write balance function to generate AVL tree
	// diagrammatic representation
	Node* root = nullptr;
	insert(root, 5);
	insert(root, 6);
	insert(root, 7);
	insert(root, 8);
	insert(root, 9);
	printPreorder(root);
	cout << endl;

	return 0;
}



