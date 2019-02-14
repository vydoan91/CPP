/*
 * Tree.h
 *
 *  Created on: Oct 17, 2018
 *      Author: vydoan
 */

#ifndef TREE_H_
#define TREE_H_

#include <iostream>
using namespace std;

class Tree {

private:
	//Node - a private, nested struct.
	//i - an int that stores the value in the tree.
	//left - a Node pointer that stores the memory address of the left child.
	//right - a Node pointer that stores the memory address of the right child.
	struct Node {
		int value;
		Node *left, *right;
	};
	//root - a Node pointer that stores the memory address of the root node.
	Node *root;

	void add(Node*&, int);
	void remove(Node*&, int);
	bool find(Node*, int);
	void print(Node*);
	void clear(Node*&);

	void printPreorder(Node*);
	void printPostorder(Node*);

public:
	Tree();
	~Tree();
	void add(int);
	void remove(int);
	bool find(int);
	void print();
	void clear();

	int getRoot();
	void printPreorder();
	void printPostorder();
};

//constructor - initializes root to null.
Tree::Tree() {
	root = nullptr;
}
//destructor - frees all memory used by the Tree.
Tree::~Tree() {
	clear();
}
//add - a public method that calls the private add method,
//passing it the root pointer and it's argument.
void Tree::add(int i) {
	add(root, i);
}

//add - a private method that is called by public add.
//Accepts the root pointer by reference and and integer
//to add to the tree as it's only arguments.
void Tree::add(Node*& root, int i) {
	if (root == nullptr) {
		root = new Node;
		root->value = i;
		root->left = nullptr;
		root->right = nullptr;
	} else {
		if (i < root->value) {
			add(root->left, i);
		} else {
			add(root->right, i);
		}
	}
}

//remove - a public method that calls the private remove method,
//passing it the root pointer and it's argument.
void Tree::remove(int i) {
	remove(root, i);
}

//remove - a private method that is called by the public remove method.
//Accepts the root pointer, by reference, and a value to search for
//and remove from the tree as it's only arguments.
void Tree::remove(Node*& root, int i) {
	if (root == nullptr) {
		return;
	}
	if (i < root->value) {
		remove(root->left, i);
	} else if (i > root->value) {
		remove(root->right, i);
	} else {
		if (root->left == nullptr && root->right == nullptr) {
			delete root;
			root = nullptr;
		} else if (root->left == nullptr && root->right != nullptr) {
			Node* temp = root;
			root = root->left;
			delete temp;
		} else if (root->left != nullptr && root->right == nullptr) {
			Node* temp = root;
			root = root->right;
			delete temp;
		} else {
			Node* temp = root->right;
			while (temp->left != nullptr) {
				temp = temp->left;
			}
			temp->left = root->left;
			temp = root;
			root = root->right;
			delete temp;
		}
	}

}
//find - a public method that calls the private find method,
//passing it's argument and the root pointer to the private find method.
//Returns the value returned by the private find method.
bool Tree::find(int i) {
	return find(root, i);
}
//find - a private method that accepts a root pointer and
//value to search for in the tree.  Returns true if it's found, false otherwise.
bool Tree::find(Node* root, int k) {
	if (root == nullptr)
		return false;

	if (k == root->value)
		return true;

	if (k < root->value)
		return find(root->left, k);
	else
		return find(root->right, k);
}
//print - a public method that calls the private print method,
//passing the root pointer to the private print method.
void Tree::print() {
	print(root);
}

//print - a private method that accepts the root pointer as
//it's only argument.  Prints the contents of the tree using in-order traversal.
void Tree::print(Node* root) {
	if (root == nullptr) {
		return;
	}
	print(root->left);
	cout << root->value << " ";
	print(root->right);
}
//clear - a public method that calls the private clear method,
//passing the root pointer to the private clear method.
void Tree::clear() {
	clear(root);
}
//clear - a private method that accepts the root pointer by reference.
//Frees all memory used by the tree.
void Tree::clear(Node*& root) {
	if (root == nullptr)
		return;
	clear(root->left);
	clear(root->right);
	delete root;
	root = nullptr;
}

int Tree::getRoot() {
	return root->value;
}

void Tree::printPreorder(Node* root) {
	if (root == nullptr) {
		return;
	}
	cout << root->value << " ";
	printPreorder(root->left);
	printPreorder(root->right);
}

void Tree::printPreorder() {
	printPreorder(root);
}

void Tree::printPostorder(Node* root) {
	if (root == nullptr) {
		return;
	}
	printPostorder(root->left);
	printPostorder(root->right);
	cout << root->value << " ";
}

void Tree::printPostorder() {
	printPostorder(root);
}
#endif /* TREE_H_ */
