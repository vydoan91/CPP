/*
 * AVLTree.h
 *
 *  Created on: Nov 1, 2018
 *      Author: vydoan
 */

#ifndef AVLTREE_H_
#define AVLTREE_H_

#include "Tree.h"

class AVLTree : public Tree {
public:
    void remove(int);

    void add(int);


private:
    int height(Node *) const;

    int difference(Node *) const;

    void rotateRight(Node *&);

    void rotateLeft(Node *&);

    void rotateLeftRight(Node *&);

    void rotateRightLeft(Node *&);

    void balance(Node *&);

    void remove(Node *&, int);

    void add(Node *&, int);

};

//height - returns the height of a tree.
//Accepts the root pointer for the tree to find the height of.
int AVLTree::height(Node *r) const {
    if (r == nullptr)
        return 0;
    int left = height(r->left);
    int right = height(r->right);
    if (left > right) {
        return (1 + left);
    } else {
        return (1 + right);
    }
}

//difference - returns balance factor for a node.
//Accepts the pointer for the node as it's argument.
int AVLTree::difference(Node *r) const {
    return (height(r->left) - height(r->right));
}

//rotateRight - implements the logic for a right rotation.
//Accepts the pointer for the node to be rotated, by reference.
void AVLTree::rotateRight(Node *&r) {
    Node *temp = r->left;
    r->left = temp->right;
    temp->right = r;
    r = temp;
}

//rotateLeft - implements the logic for a left rotation.
//Accepts the pointer for the node to be rotated , by reference.
void AVLTree::rotateLeft(Node *&r) {
    Node *temp = r->right;
    r->right = temp->left;
    temp->left = r;
    r = temp;
}

//rotateRightLeft - implements the logic for a right-left rotation.
//Accepts the pointer for the node to be rotated , by reference.
void AVLTree::rotateRightLeft(Node *&r) {
    rotateRight(r->right);
    rotateLeft(r);
}

//rotateLeftRight - implements the logic for a left-right rotation.
//Accepts the pointer for the node to be rotated , by reference.
void AVLTree::rotateLeftRight(Node *&r) {
    rotateLeft(r->left);
    rotateRight(r);
}

//balance - brings the AVLTree back into balance, if necessary.
//Accepts the pointer for a node that needs to be adjusted.
void AVLTree::balance(Node *&r) {
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

void AVLTree::add(int i) {
    add(root, i);
    balance(root);
}

void AVLTree::add(Node *&r, int i) {
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

void AVLTree::remove(int i) {
    remove(root, i);
    balance(root);
}

void AVLTree::remove(Node *&r, int i) {
    if (r == nullptr)
        return;
    else if (i < r->i)
        remove(r->left, i);
    else if (i > r->i)
        remove(r->right, i);
    else {
        Node *p;

        if (r->left == nullptr && r->right == nullptr)        // no kids
        {
            delete r;
            r = nullptr;
        } else if (r->left != nullptr && r->right == nullptr)    // left kid
        {
            p = r;
            r = r->left;
            delete p;
        } else if (r->left == nullptr && r->right != nullptr)    // right kid
        {
            p = r;
            r = r->right;
            delete p;
        } else                                                // two kids
        {
            p = r->right;

            while (p->left)
                p = p->left;

            p->left = r->left;
            p = r;
            r = r->right;

            delete p;
        }
    }
    balance(r);
}

#endif /* AVLTREE_H_ */
