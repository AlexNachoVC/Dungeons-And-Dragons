#pragma once

#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    T Data;
    Node<T> *next;

    Node(T value) {
        Data = value;
        next = nullptr;
    }
}; 

template <typename T>
class Queue {
private: 
    Node<T> *head;
    Node<T> *tail;

public: 
    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    ~Queue() {
        while (head) {
            deque();
        }
    }
    
    bool enqueue(T value) {
        Node<T> *newNode = new (nothrow) Node<T>(value);
        if (!newNode) {
            return false;
        }

        if (!tail) {
            tail = head = newNode;  
            return true;
        }

        tail->next = newNode;
        tail = newNode;

        return true;
    }

    bool deque() {
        if (!head) {
            return false;
        }

        Node<T> *tmp = head;
        head = head->next;
        if (!head) {
            tail = nullptr;
        }
        delete tmp;

        return true;
    }

    T* peek() {
        if (head != nullptr) {
            return &head->Data;
        }
        throw runtime_error("Queue is empty");
    }

    void printQueue() {
        Node<T> *curr = head;

        while (curr) {
            cout << curr->Data << " ";
            curr = curr->next;
        }
        cout << "\n";
    }

    bool isEmpty() {
        return head == nullptr;
    }
};