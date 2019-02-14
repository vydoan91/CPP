/*
 * AVLTree.cpp
 *
 *  Created on: Nov 1, 2018
 *      Author: vydoan
 */
#include <iostream>
using namespace std;

struct Node {
	int i;
	Node* left;
	Node* right;
};

int height(Node* r) {
	if (r == nullptr)
		return 0;

	int LH = height(r->left);
	int RH = height(r->right);

	if (LH > RH)
		return (1 + LH);
	else
		return (1 + RH);
}

int difference(Node* r) {
	int diff = height(r->left) - height(r->right);
	return diff;
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
	} else if (difference(r) == 2) {
		if (difference(r->left) == 1) {
			rotateRight(r);
		} else {
			rotateLeftRight(r);
		}
	}
}

void add(Node*& r, int i) {
	if (r == nullptr) {
		r = new Node;
		r->i = i;
		r->left = nullptr;
		r->right = nullptr;
	} else if (i < r->i) {
		add(r->left, i);
	} else {
		add(r->right, i);
	}
	balance(r);
}

void remove(Node*& r, int i) {
	if (r == nullptr)
		return;
	else if (i < r->i)
		remove(r->left, i);
	else if (i > r->i)
		remove(r->right, i);
	else if (i == r->i) {
		Node* p;

		if (r->left == nullptr && r->right == nullptr) {
			delete r;
			r = nullptr;
		} else if (r->left != nullptr && r->right == nullptr) {
			p = r;
			r = r->left;
			delete p;
		} else if (r->left == nullptr && r->right != nullptr) {
			p = r;
			r = r->right;
			delete p;
		} else	{
			p = r->right;

			while (p->left)
				p = p->left;

			p->left = r->left;
			p = r;
			r = r->right;

			delete p;
		}
	}
}

void printPreorder(Node* r) {
	if (r == nullptr)
		return;
	cout << r->i << " ";
	printPreorder(r->left);
	printPreorder(r->right);
}

int main() {
	Node* root = nullptr;
	add(root, 6);
	cout << root->i << endl;

	add(root, 8);
	add(root, 10);
	add(root, 9);
	printPreorder(root);
	cout << endl;
	cout << root->i << endl;
	remove(root, 6);
	balance(root);
	printPreorder(root);
	return 0;
}

