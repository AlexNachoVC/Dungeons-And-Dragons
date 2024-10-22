#pragma once

#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T> *next;

    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
class Stack {
private:
    Node<T> *top;
    
public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {

    }

    bool push (T data) {
        Node<T> *newNode = new(nothrow) Node<T>(data);

        if (!newNode) {
            return false;
        }

        if (!top) {
            top = newNode;
            return true;
        }

        newNode->next = top;
        top = newNode;
        return true;
    } 

    bool pop() {
        if (!top) {
            return false;
        }

        Node<T> *tmp = top;
        top = top->next;
        delete tmp;

        return true;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int *getTop() {
        if (!top) {
            return nullptr;
        }
        return &top->data;
    }

    void print() {
        Node<T> *curr = top;

        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n";
        }

};