/*
 * tree.cpp
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
void remove(Node*&, int);
bool find(Node*, int);
void printInorder(Node*);
void clear(Node*&);
void printPreorder(Node*);
void printPostorder(Node*);

int main() {
	Node* root = nullptr;
	insert(root, 44);
	insert(root, 17);
	insert(root, 78);
	insert(root, 50);
	insert(root, 88);
	insert(root, 48);
	insert(root, 32);
	insert(root, 62);
	printInorder(root);
	cout << endl;

	cout << find(root, 48) << endl;
	cout << find(root, 2) << endl;

	printPreorder(root);
	cout << endl;

	printPostorder(root);
	cout << endl;
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

void remove(Node*& root, int k) {

}

bool find(Node* root, int k) {
	if (root == nullptr)
		return false;

	if (k == root->value)
		return true;

	if (k < root->value)
		return find(root->left, k);
	else
		return find(root->right, k);
}

void printInorder(Node* root) {
	if (root == nullptr) {
		return;
	}
	printInorder(root->left);
	cout << root->value << " ";
	printInorder(root->right);
}

void clear(Node*& root) {
	if(root == nullptr)
		return;
	clear(root->left);
	clear(root->right);
	delete root;
	root = nullptr;

}

void printPreorder(Node* root) {
	if (root == nullptr) {
		return;
	}
	cout << root->value << " ";
	printPreorder(root->left);
	printPreorder(root->right);
}

void printPostorder(Node* root) {
	if (root == nullptr) {
		return;
	}
	printPostorder(root->left);
	printPostorder(root->right);
	cout << root->value << " ";
}

