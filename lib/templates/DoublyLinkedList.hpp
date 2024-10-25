#pragma once

#include <iostream>

using namespace std;

template <typename T>
class DoublyLinkedListNode {
public:
    T data;
    DoublyLinkedListNode<T> *prev;
    DoublyLinkedListNode<T> *next;

    DoublyLinkedListNode(T data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

template <typename T>
class DoublyLinkedList {
private: 
    DoublyLinkedListNode<T> *head;
    DoublyLinkedListNode<T> *tail;
public: 
    DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    }

    ~DoublyLinkedList() {
        deleteLinkedList();
    }

    bool prepend(T value) {
        DoublyLinkedListNode<T> *newNode = new(nothrow) DoublyLinkedListNode<T>(value);
        if (!newNode) {
            return false;
        }

        if (!head) {
            head = tail = newNode;
            return true;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return true;
    }

    bool append(T value) {
        DoublyLinkedListNode<T> *newNode = new(nothrow) DoublyLinkedListNode<T>(value);
        if (!newNode) {
            return false;
        }

        if (!tail) {
            tail = head = newNode;
            return true;
        }

        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        return true;
    }

    bool insertAt(T value, int position) {
        if (position < 1) {
            return false;
        }

        if (position == 1) {
            return prepend(value);
        }

        DoublyLinkedListNode<T> *newNode = new(nothrow) DoublyLinkedListNode<T>(value);
        if (!newNode) {
            return false;
        }

        DoublyLinkedListNode<T> *tmp = head;

        for (int i = 1; tmp != nullptr && i < position - 1; i++) {
            tmp = tmp->next;
        }

        if (tmp == nullptr) {
            return false;
        }

        newNode->next = tmp->next;
        newNode->prev = tmp;
        if (tmp->next != nullptr) {
            tmp->next->prev = newNode;
        }
        tmp->next = newNode;
        return true;
    }

    bool insertOnOrder(T value) {
        DoublyLinkedListNode<T> *newNode = nullptr;
        newNode = new (nothrow) Node(value);

        if (!newNode) {
            return false;
        }

        newNode->next = nullptr;

        if (!head) {
            head = tail = newNode;
            return true;
        }

        if (value < head->data) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return true;
        }

        DoublyLinkedListNode<T> *current = head;
        while (current->next && current->next->data < value) {
            current = current->next;
        }

        newNode->next = current->next;
        newNode->prev = current;

        if (current->next) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }

        current->next = newNode;
        return true;
    }

    bool deleteElement(T element) {
        if (!head) {
            return false;
        }

        if (head->data == element) {
            DoublyLinkedListNode<T> *tmp = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            delete tmp;
            return true;
        }

        DoublyLinkedListNode<T> *current = head;

        while (current && current->data != element) {
            current = current->next;
        }

        if (!current) {
            return false;
        }

        if (current->next) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }

        if (current->prev) {
            current->prev->next = current->next;
        }

        delete current;
        return true;
    }

    bool deleteAtBeginning() {
        if (!head) {
            return false;
        }

        DoublyLinkedListNode<T> *tmp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete tmp;
        return true;
    }

    bool deleteAtEnd() {
        if (!head) {
            return false;
        }

        DoublyLinkedListNode<T> *tmp = tail;
        tail = tail->prev;

        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }

        delete tmp;
        return true;
    }

    bool deleteAt(int position) {
        if (!head || position < 1) {
            return false;
        }

        if (position == 1) {
            return deleteAtBeginning();
        }

        DoublyLinkedListNode<T> *tmp = head;

        for (int i = 1; tmp != nullptr && i < position; i++) {
            tmp = tmp->next;
        }

        if (tmp == nullptr) {
            return false;
        }

        if (tmp->next != nullptr) {
            tmp->next->prev = tmp->prev;
        }
        if (tmp->prev != nullptr) {
            tmp->prev->next = tmp->next;
        }

        delete tmp;
        return true;
    }

    void deleteLinkedList() {
        while (head) {
            DoublyLinkedListNode<T> *tmp = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            }
            delete tmp;
        }
        tail = nullptr;
    }

    void printListForwards() {
        if (!head) {
            return;
        }

        DoublyLinkedListNode<T> *tmp = head;

        while (tmp) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << "\n";
    }

    void printListBackwards() {
        if (!head) {
            return;
        }

        DoublyLinkedListNode<T> *tmp = tail;

        while (tmp) {
            cout << tmp->data << " ";
            tmp = tmp->prev;
        }
        cout << "\n";
    }
};