#pragma once

#include <iostream>

using namespace std;

template <typename T>
class StackNode {
public:
    T data;
    StackNode<T> *next;

    StackNode(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
class Stack {
private:
    StackNode<T> *top;
    
public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {

    }

    bool push (T data) {
        StackNode<T> *newNode = new(nothrow) StackNode<T>(data);

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

        StackNode<T> *tmp = top;
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
        StackNode<T> *curr = top;

        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n";
        }

};