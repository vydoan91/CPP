/*
 * lab8.cpp
 *
 *  Created on: Oct 18, 2018
 *      Author: vydoan
 */

#include <iostream>
using namespace std;

struct Node {
	int value;
	Node *left, *right;
};

void insert(Node*&, int);
void printInorder(Node*);

int main() {
	// create binary search tree (using insert function)-7/8 nodes
	Node* root = nullptr;
	insert(root, 44);
	insert(root, 17);
	insert(root, 78);
	insert(root, 50);
	insert(root, 88);
	insert(root, 48);
	insert(root, 32);
	insert(root, 62);
	cout << root->value << endl;
	// print nodes in "in-order"
	printInorder(root);
	cout << endl;
	cout << root->value << endl;
	return 0;
}

void insert(Node*& root, int k) {
	if (root == nullptr) {
		root = new Node;
		root->value = k;
		root->left = nullptr;
		root->right = nullptr;
	} else {
		if (k < root->value) {
			insert(root->left, k);
		} else {
			insert(root->right, k);
		}
	}
}

void printInorder(Node* root) {
	if (root == nullptr) {
		return;
	}
	printInorder(root->left);
	cout << root->value << " ";
	printInorder(root->right);
}
