#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <functional>
#include <stdexcept>
#include <iostream>
#include "node.h"

template<class T>
class Queue;

template<class T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    int getSize();
    void clear();
    void addFirst(T);
    void addNode(Node<T>*);
    void pushBack(T);
    bool deleteAt(int);
    void updateAt(T, int);
    void print(int, int);
    void sort();
    void opAt(std::function<void(Node<T>*)>, int);
    void forEach(std::function<void(Node<T>*, int)> f, int from = 0);
    LinkedList<T> sublist(int from = 0, int to = -1);
    Node<T>* at(int);
    Node<T>* operator[](int);
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
    Node<T>* merge(Node<T>*, Node<T>*);
};

template<class T>
LinkedList<T>::LinkedList() {
    head = tail = nullptr;
    size = 0;
}

template<class T>
int LinkedList<T>::getSize() {
    return size;
}

template<class T>
void LinkedList<T>::pushBack(T data) {
    if (head == nullptr) {
        head = new Node<T>(data, nullptr, nullptr);
        tail = head;
        size += 1;
        return;
    }
    Node<T>* node = new Node<T>(data, tail, nullptr);
    tail->setNext(node);
    tail = node;
    size++;
}

template<class T>
void LinkedList<T>::addFirst(T data) {
    if (head == nullptr) {
        head = new Node<T>(data, nullptr, nullptr);
        tail = head;
        size += 1;
        return;
    }
    Node<T>* node = new Node<T>(data, nullptr, head);
    head->setPrev(node);
    head = node;
    size++;
}

template<class T>
// Risky OP. Should only be used for sorting
void LinkedList<T>::addNode(Node<T>* node) {
    if (head == nullptr) {
        head = node;
        tail = head;
        node->setPrev(nullptr);
        node->setNext(nullptr);
        size++;
        return;
    }
    tail->setNext(node);
    size++;
}


template<class T>
void LinkedList<T>::opAt(std::function<void(Node<T>*)> f, int i) {
    if (i >= size) {
        throw std::out_of_range("Index out of range");
    }
    if (i == 0) {
        f(head);
        return;
    }
    if (i == size - 1) {
        f(tail);
        return;
    }
    Node<T>* result;
    if (i < (size - 1) / 2) {
        result = head;
        for (int j = 0; j < i; j++) {
            result = result->getNext();
        }
    }
    result = tail;
    for (int j = size - 1; j > i; j--) {
        result = result->getPrev();
    }
    f(result);
}

template<class T>
void LinkedList<T>::forEach(std::function<void(Node<T>*, int)> f, int from) {
    if (from >= size) {
        throw std::out_of_range("Index out of range");
    }
    Node<T>* result;
    if (from < (size - 1) / 2) {
        result = head;
        for (int j = from; j < size; j++) {
            f(result, j);
            result = result->getNext();
        }
        return;
    }
    result = tail;
    for (int j = size - 1; j > from - 1; j--) {
        f(result, j);
        result = result->getPrev();
    }
}

template<class T>
Node<T>* LinkedList<T>::at(int i) {
    if (i >= size) {
        throw std::out_of_range("Index out of range");
    }
    if (i == 0) {
        return head;
    }
    if (i == size - 1) {
        return tail;
    }
    Node<T>* result;
    if (i < (size - 1) / 2) {
        result = head;
        for (int j = 0; j < i; j++) {
            result = result->getNext();
        }
    }
    result = tail;
    for (int j = size - 1; j > i; j--) {
        result = result->getPrev();
    }
    return result;
}

template<class T>
Node<T>* LinkedList<T>::operator[](int i) {
    return at(i);
}

template<class T>
bool LinkedList<T>::deleteAt(int i) {
    if (size == 1 && i == 0) {
        delete head;
        size--;
        clear();
        return true;
    }
    opAt([this, i](Node<T>* e) {
        Node<T>* prev = e->getPrev();
        Node<T>* next = e->getNext();
        if (prev != nullptr) {
            prev->setNext(next);
        }
        else {
            // Change head
            head = next;
            head->setPrev(nullptr);
        }
        if (next != nullptr) {
            next->setPrev(prev);
        }
        else {
            tail = prev;
        }
        size--;
        delete e;
        }, i);
    return true;
}

template<class T>
LinkedList<T> LinkedList<T>::sublist(int from, int to) {
    // These lists will share nodes with the base list, it is just
    // a method for convenience. Therefore, DO NOT delete nodes from
    // the base list/sublist when the method is used.
    LinkedList<T> newList;
    int upper = to == -1 ? size - 1 : to;
    newList.head = at(from);
    newList.tail = at(upper);
    newList.size = upper - from;  // Maybe +1 here
    return newList;
}

template<class T>
Node<T>* LinkedList<T>::merge(Node<T>* l1, Node<T>* l2) {
    std::cout << "== MERGE CALL ==" << std::endl;
    if (l1 != nullptr) {
        std::cout << "l1: " << l1->getData() << std::endl;
    }
    if (l2 != nullptr) {
        std::cout << "l2: " << l2->getData() << std::endl;
    }
    Node<T>* result = nullptr;
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->getData() > l2->getData()) {
            std::cout << "Adding " << l2->getData() << " to list" << std::endl;
            Node<T>* tmp = l2;
            l2 = l2->getNext();
            tmp->setNext(nullptr);
            if (result == nullptr) {
                result = tmp;
                tmp->setPrev(nullptr);
            }
            else {
                tmp->setPrev(result);
                result->setNext(tmp);
                // result = tmp;
            }
        }
        else {
            std::cout << "Adding " << l1->getData() << " to list" << std::endl;
            Node<T>* tmp = l1;
            l1 = l1->getNext();
            tmp->setNext(nullptr);
            if (result == nullptr) {
                tmp->setPrev(nullptr);
                result = tmp;
            }
            else {
                tmp->setPrev(result);
                result->setNext(tmp);
                // result = tmp;
            }
        }
    }
    while (l1 != nullptr) {
        std::cout << "Adding " << l1->getData() << " to list" << std::endl;
        Node<T>* tmp = l1;
        l1 = l1->getNext();
        tmp->setPrev(result);
        tmp->setNext(nullptr);
        result->setNext(tmp);
        // result = tmp;
    }
    while (l2 != nullptr) {
        std::cout << "Adding " << l2->getData() << " to list" << std::endl;
        Node<T>* tmp = l2;
        l2 = l2->getNext();
        tmp->setPrev(result);
        tmp->setNext(nullptr);
        result->setNext(tmp);
        // result = tmp;
    }
    std::cout << "== MERGE CALL CONT. ==" << std::endl;
    Node<T>* temp = result;
    while (temp != nullptr) {
        if (temp == nullptr) {
            std::cout << "breaking on null" << std::endl;
            break;
        }
        std::cout << temp->getData() << std::endl;
        temp = temp->getPrev();
    }
    std::cout << "== END CALL ==" << std::endl;
    return result;
}

template<class T>
void LinkedList<T>::sort() {
    // Here we need to queues
    // The first to store all the nodes w/next and prev
    // pointers. The second one to remove them. If we were
    // to remove them directly in the first one, the list would break.
    Queue<Node<T>*> nodes;
    Queue<Node<T>*> queue;
    forEach([this, &nodes](Node<T>* e, int i) {
        //std::cout << "Nodes i: " << i << std::endl;
        nodes.push(e);
        //std::cout << "Nodes size: " << nodes.size() << std::endl;
        });
    std::cout << "Nodes size: " << nodes.size() << std::endl;
    while (!nodes.isEmpty()) {
        Node<T>* e = nodes.poll();
        e->setNext(nullptr);
        e->setPrev(nullptr);
        queue.push(e);
    }
    std::cout << "done with first wh" << std::endl;
    while (queue.size() > 1) {
        Node<T>* l1 = queue.poll();
        Node<T>* l2 = queue.poll();
        Node<T>* res = merge(l1, l2);
        if (res == nullptr) continue;
        queue.push(res);
        std::cout << "Queue size: " << queue.size() << std::endl;
    }
    std::cout << "done whiling" << std::endl;
    // Set the new head and tail
    Node<T>* newHead = queue.poll();
    this->head = newHead;
    Node<T>* next = head->getNext();
    std::cout << "next node: " << next->getData() << std::endl;
    Node<T>* newTail = head;
    while (newTail->getNext() != nullptr) {
        std::cout << "iter" << std::endl;
        newTail = newTail->getNext();
    }
    this->tail = newTail;
    std::cout << "New head: " << head->getData() << std::endl;
    std::cout << "New tail: " << tail->getData() << std::endl;
}

template<class T>
void LinkedList<T>::print(int from, int to) {
    for (int i = from; i <= to; i++) {
        std::cout << (at(i)->getData()) << std::endl;
    }
}

template<class T>
void LinkedList<T>::clear() {
    // Free the memory
    Node<T>* current = head;
    for (int i = 0; i < size; i++) {
        Node<T>* temp = current;
        current = temp->getNext();
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<class T>
LinkedList<T>::~LinkedList() {
    clear();
}

template<class T>
class Queue {
public:
    Queue();
    void push(T data);
    T poll();
    bool isEmpty();
    int size();
private:
    LinkedList<T> queue;
};


template<class T>
Queue<T>::Queue() {}

template<class T>
void Queue<T>::push(T data) {
    queue.addFirst(data);
}

template<class T>
T Queue<T>::poll() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    T e = queue[queue.getSize() - 1]->getData();
    queue.deleteAt(queue.getSize() - 1);
    return e;
}

template<class T>
bool Queue<T>::isEmpty() {
    return queue.getSize() == 0;
}

template<class T>
int Queue<T>::size() {
    return queue.getSize();
}

#endif