/*
 * Tree.h
 *
 *  Created on: Nov 1, 2018
 *      Author: vydoan
 */

#ifndef TREE_H_
#define TREE_H_

#include<iostream>

using std::cout;
using std::endl;

class Tree {
protected:
    struct Node {
        int i;
        Node *left, *right;
    } *root;

private:
    void add(Node *&, int);

    void remove(Node *&, int);

    bool find(Node *, int) const;

    void print(Node *) const;

    void clear(Node *&);

    void printPreorder(Node *);

public:
    Tree();

    ~Tree();

    void add(int);

    void remove(int);

    bool find(int) const;

    void print() const;

    void clear();

    void printPreorder();

};

Tree::Tree() {
    root = nullptr;
}

Tree::~Tree() {
    clear(root);
}

void Tree::add(int i) {
    add(root, i);
}

void Tree::add(Node *&r, int i) {
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
}

void Tree::remove(int i) {
    remove(root, i);
}

void Tree::remove(Node *&r, int i) {
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
}

bool Tree::find(int i) const {
    return find(root, i);
}

bool Tree::find(Node *r, int i) const {
    if (r == nullptr)
        return false;
    else if (r->i == i)
        return true;
    else if (i < r->i)
        return find(r->left, i);
    else
        return find(r->right, i);
}

void Tree::print() const {
    print(root);
}

void Tree::print(Node *r) const {
    if (r != nullptr) {
        print(r->left);
        cout << r->i << "\t";
        print(r->right);
    }
}

void Tree::clear() {
    clear(root);
    root = nullptr;
}

void Tree::clear(Node *&r) {
    if (r != nullptr) {
        clear(r->left);
        clear(r->right);
        delete r;
    }
}

void Tree::printPreorder(Node *r) {
    if (r != nullptr) {
        cout << r->i << "\t";
        printPreorder(r->left);
        printPreorder(r->right);
    }
}

void Tree::printPreorder() {
    printPreorder(root);
}
#endif /* TREE_H_ */
