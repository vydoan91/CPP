//
// Created by VY DOAN on 12/4/18.
//

#ifndef HW7_HASHTABLE_H
#define HW7_HASHTABLE_H

#include <string>
#include <iostream>

using namespace std;

class HashTable {
private:
    struct Element {
        //key -  Stores the string passed to the object through the insert method.
        string key;

        // mark - an variable set to
        // 2 if the element is being used,
        // 1 if it was used but then was deleted, and
        // 0 if it was never used.
        int mark;
    };

    //table - an Element pointer that holds the memory address of
    //a dynamically allocated array of Elements.
    Element *table;

    //size - stores the size of the Element array.
    int size;

    int hash(string) const;

public:
    HashTable(int);

    ~HashTable();

    void insert(string);

    void remove(string);

    bool isFull() const;

    bool isEmpty() const;

    void clear();

    void print() const;

    bool find(string) const;

};

//constructor - accepts an integer as it's only argument,
// creating a hash table that can store that many values
// (a dynamically allocated array of Elements).
HashTable::HashTable(int s) {
    size = s;
    table = new Element[size];
    for (int i = 0; i < size; i++) {
        table[i].mark = 0;
    }
}

//destructor - frees all memory used.
HashTable::~HashTable() {
    delete[] table;
}

//hash - The hash function.  It accepts a String as it's only
//argument and returns an index into the hash table.
int HashTable::hash(string key) const {
    int sum = 0;
    for (int i = 0; i < key.length(); i++) {
        sum = sum + (int) key.at(i);
    }
    return sum % size;
}

//insert() - accepts a string as it's only argument,
// which is added to the hash table, setting the element's
// mark where it is stored to 2.
void HashTable::insert(string key) {
    if (!isFull()) {
        int hi = hash(key);
        while (table[hi].mark == 2) {
            hi = (hi + 1) % size;
        }
        table[hi].key = key;
        table[hi].mark = 2;
    }
}

//remove() - accepts a string as it's only argument,
// and removes the string from the hash table (if found)
// by setting it's mark to 1.
void HashTable::remove(string key) {
    if (!isEmpty()) {
        int hi = hash(key);
        int i = 0;
        while (i < size && table[hi].mark != 0) {
            if (table[hi].key == key) {
                table[hi].mark = 1;
                break;
            }
            i++;
            hi = (hi + 1) % size;
        }
    }
}

//isFull() - returns true if the hash table is full, false otherwise.
bool HashTable::isFull() const {
    for (int i = 0; i < size; i++) {
        if (table[i].mark == 0 || table[i].mark == 1)
            return false;
    }
    return true;
}

//isEmpty() - returns true if the hash table is empty, false otherwise.
bool HashTable::isEmpty() const {
    for (int i = 0; i < size; i++) {
        if (table[i].mark == 2)
            return false;
    }
    return true;
}

//find() - accepts a string as it's only argument.
// Returns true if it is found in the hash table, false otherwise.
bool HashTable::find(string key) const {
    if (!isEmpty()) {
        int hi = hash(key);
        int i = 0;
        while (i < size && table[hi].mark != 0) {
            if (table[hi].key == key && table[hi].mark == 2) {
                return true;
            }
            i++;
            hi = (hi + 1) % size;
        }
    }
    return false;
}

//clear() - empties the hash table by setting each elements mark to 0.
void HashTable::clear() {
    if (!isEmpty()) {
        for (int i = 0; i < size; i++) {
            table[i].mark = 0;
        }
    }
}

//print() - displays the contents of the hash table to the screen.
// That is, only the elements that are being used (marked with 2)
void HashTable::print() const {
    if (!isEmpty()) {
        for (int i = 0; i < size; i++) {
            if (table[i].mark == 2) {
                cout << i << " " << table[i].key << " ";
            }
        }
        cout << endl;
    }
}

#endif //HW7_HASHTABLE_H
