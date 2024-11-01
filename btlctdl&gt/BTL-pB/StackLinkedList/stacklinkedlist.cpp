//Tm
#include<bits/stdc++.h>
using namespace std;
#ifndef __STACKLL__
#define __STACKLL__


template<typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
};

template<typename T>
class StackLinkedList {
private:
    Node<T>* top;
    int Size;

public:
    StackLinkedList() {
        top = nullptr;
        Size = 0;
    }

    ~StackLinkedList() {
        clear();
    }

    StackLinkedList(const StackLinkedList<T>& s) {
        top = nullptr;
        Size = 0;
        Node<T>* current = s.top;
        while (current != nullptr) {
            push(current->data);
            current = current->next;
        }
    }

    StackLinkedList<T>& operator=(const StackLinkedList<T>& s) {
        if (this == &s) return *this;
        clear();
        top = nullptr;
        Size = 0;
        Node<T>* current = s.top;
        while (current != nullptr) {
            push(current->data);
            current = current->next;
        }
        return *this;
    }

    int size() const {
        return Size;
    }

    bool empty() const {
        return Size == 0;
    }

    T& getTop() {
        if (empty()) {
            throw runtime_error("Stack is empty. Cannot access top element.");
        }
        return top->data;
    }

    void pop() {
        if (empty()) return;
        Node<T>* temp = top;
        top = top->next;
        delete temp;
        Size--;
    }

    void clear() {
        while (!empty()) {
            pop();
        }
    }

    void push(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = top;
        top = newNode;
        Size++;
    }
};

#endif