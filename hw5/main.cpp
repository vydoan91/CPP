/*
 * main.cpp
 *
 *  Created on: Nov 1, 2018
 *      Author: vydoan
 */
#include "AVLTree.h"

int main() {
    AVLTree tree;
    tree.add(9);
    tree.add(5);
    tree.add(10);
    tree.add(1);
    tree.add(6);
    tree.add(11);
    tree.add(0);
    tree.add(2);
    tree.add(3);
    tree.printPreorder();
    cout << endl;

    tree.remove(10);
    tree.printPreorder();

    return 0;
}



