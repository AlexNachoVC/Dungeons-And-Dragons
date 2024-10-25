#pragma once

#include <iostream>

using namespace std;

template <typename T>
class QueueNode {
public:
    T Data;
    QueueNode<T> *next;

    QueueNode(T value) {
        Data = value;
        next = nullptr;
    }
}; 

template <typename T>
class Queue {
private: 
    QueueNode<T> *head;
    QueueNode<T> *tail;

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
        QueueNode<T> *newNode = new (nothrow) QueueNode<T>(value);
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

        QueueNode<T> *tmp = head;
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
        QueueNode<T> *curr = head;

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