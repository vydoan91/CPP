#include "HashTable.h"

int main() {
    HashTable table(5);
    table.insert("john");
    table.insert("vy");
    table.insert("meo");
    table.print();

    table.remove("meo");
    table.print();

    cout << table.find("meo") << endl;
    return 0;
}