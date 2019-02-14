/*
 * main.cpp
 *
 *  Created on: Oct 17, 2018
 *      Author: vydoan
 */

#include "Tree.h"
int main() {
	Tree tree;
	tree.add(5);
	tree.add(3);
	tree.add(9);
	tree.add(7);
	tree.add(6);
	tree.add(1);
	tree.add(4);

	tree.print();
	cout << endl;
	tree.printPreorder();
	cout << endl;
	tree.printPostorder();
	cout << endl;
	cout << tree.getRoot() << endl;

	tree.remove(5);
	tree.print();
	cout << endl;
	cout << tree.getRoot() << endl;

	tree.remove(3);
	tree.print();
	cout << endl;
	cout << tree.getRoot() << endl;

	tree.clear();
	tree.print();
	cout << endl;

}

