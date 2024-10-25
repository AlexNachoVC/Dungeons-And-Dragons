#pragma once

#include <iostream>

using namespace std;

template <typename T>
class SinglyLinkedListNode {
public:
    T data;
    SinglyLinkedListNode<T> *next;

    SinglyLinkedListNode() {
        next = nullptr;
    };
};

template <typename T>
class LinkedList {
private:
    SinglyLinkedListNode<T> *head;
public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {   
        deleteList();
    }

    // O(n)
    bool insertAtEnd(T value) {
        SinglyLinkedListNode<T> *tmp = nullptr, *newNode = nullptr;
        newNode = new (nothrow) SinglyLinkedListNode<T>;

        if (!newNode) {
            return false;
        }

        newNode->data = value;
        if (!head) {
            head = newNode;
            return true;
        }

        tmp = head;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
        return true;
    }

    // O(1)
    bool insertAtBeginning(T value) {
        SinglyLinkedListNode<T> *newNode = new(nothrow) SinglyLinkedListNode<T>;
        if (!newNode) {
            return false;
        }

        newNode->data = value;
        newNode->next = head;
        head = newNode;
        return true;
    }

    // O(n)
    bool insertOnOrder(T value) {
        SinglyLinkedListNode<T> *newNode = nullptr;
        newNode = new (nothrow) SinglyLinkedListNode<T>;

        if (!newNode) {
            return false;
        }

        newNode->data = value;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
            return true;
        }

        if (value < head->data) {
            newNode->next = head;
            head = newNode;
            return true;
        }

        SinglyLinkedListNode<T> *current = head;
        while (current->next && current->next->data < value) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
        return true;
    }

    // O(n)
    void printList() {
        SinglyLinkedListNode<T> *tmp = head;

        while (tmp) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << "\n";
    }

    // O(n)
    void deleteList() {
        if (!head) {
            return;
        }
        while (head) {
            SinglyLinkedListNode<T> *tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    // O(n)
    bool deleteElement(T element) {
        if (!head) {
            return false;
        }

        if (head->dato == element) {
            SinglyLinkedListNode<T> *tmp = head;
            head = head->next;
            delete tmp;
            return true;
        }

        SinglyLinkedListNode<T> *current = head;
        SinglyLinkedListNode<T> *previous = nullptr;

        while (current && current->dato != element) {
            previous = current;
            current = current->next;
        }

        if (!current) {
            return false;
        }

        previous->next = current->next;
        delete current;
        return true;

    }

    // O(n)
    bool deleteAtEnd() {
        if (!head) {
            return false;
        }

        if (!head->next) {
            delete head;
            head = nullptr;
            return true;
        }

        SinglyLinkedListNode<T> *current = head;
        while (current->next->next) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
        return true;
    }

    // O(n)
    int cuentaMenores(int dato) {
        int count(0);

        SinglyLinkedListNode<T> *current = head;
        while (current) {
            if (current->data < dato) {
                count++;
            }
            current = current->next;
        }
        return count;
    }
};