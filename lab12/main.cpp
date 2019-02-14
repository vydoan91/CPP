#include <string>
#include <iostream>

using namespace std;

class HashTable {
private:
    struct Element {
        string key;
        // 2 if the element is being used,
        // 1 if it was used but then was deleted, and
        // 0 if it was never used.
        int mark;
    };
    Element *table;

    int size;

    int hash(string) const;

public:
    HashTable(int);

    ~HashTable();

    bool isFull();

    void insert(string);

    void print() const;
};

int main() {
    // Create "HashTable" using "insert" function
    HashTable table(6);
    table.insert("Florida");
    table.insert("Washington");
    table.insert("Colorado");
    // map the value "California" in hashtable
    table.insert("California");
    table.print();
    return 0;
}

HashTable::HashTable(int s) {
    size = s;
    table = new Element[size];
    for (int i = 0; i < size; i++) {
        table[i].mark = 0;
    }
}

HashTable::~HashTable() {
    delete[] table;
}

int HashTable::hash(string key) const {
    int sum = 0;
    for (int i = 0; i < key.length(); i++) {
        sum = sum + (int) key.at(i);
    }
    return sum % size;
}

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

bool HashTable::isFull() {
    for (int i = 0; i < size; i++) {
        if (table[i].mark == 0 || table[i].mark == 1)
            return false;
    }
    return true;
}

void HashTable::print() const {
    for (int i = 0; i < size; i++) {
        if (table[i].mark == 2) {
            cout << i << " " << table[i].key << " ";
        }
    }
    cout << endl;
}