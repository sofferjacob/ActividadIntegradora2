#include "linked_list.h"
#include <iostream>

using namespace std;

int main() {
    LinkedList<int> list;
    for (int i = 10; i >= 0; i--) {
        list.pushBack(i);
    }
    cout << "Size: " << list.getSize() << endl;
    list.print(0, list.getSize() - 1);
    list.sort();
    cout << "==" << endl;
    list.print(0, list.getSize() - 1);
    return 0;
}