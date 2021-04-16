/*
Jacobo Soffer Levy
A01028653
File used to test the
linked list implementation.
Not included in binary
Modified: 13/04/21
*/
#include "linked_list.h"
#include <iostream>

using namespace std;

int main() {
    LinkedList<int> list;
    list.pushBack(48);
    list.pushBack(5);
    list.pushBack(60);
    list.pushBack(16);
    list.pushBack(15);
    list.pushBack(15);
    list.pushBack(1);
    list.pushBack(100);
    cout << "Size: " << list.getSize() << endl;
    list.print(0, list.getSize() - 1);
    list.sort();
    cout << "==" << endl;
    list.print(0, list.getSize() - 1);
    return 0;
}