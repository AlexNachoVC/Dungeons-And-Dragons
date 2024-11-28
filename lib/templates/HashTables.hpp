#pragma once
#include "DoublyLinkedList.hpp"

template <typename T>
class HashTable {
private:
    DoublyLinkedList<T> *table;
    unsigned int size;

    unsigned int getIndex(T data) {
        if(!hashFunction) {
            return 0;
        }
        return HashFunction(data, size);
    }
    
    using HashFunction = unsigned int (*)(T&, unsigned int tableSize);
    HashFunction hashFunction;

public:
    HashTable() {
        hashFunction = nullptr;
        table = nullptr;
        size = 0;
    }
    ~HashTable() { deleteTable(); }

    bool createTable(unsigned int nSize, HashFunction hashF) {
        if (!nSize || table || !hashF) {
            return false;
        }

        table = new(nothrow) DoublyLinkedList<T>[nSize];
        if (!table) {
            return false;
        }
        
        size = nSize;
        hashFunction = hashF;
        return true;
    }

    void deleteTable() {
        if (!size) {
            return;
        }

        if (table) {
            delete [] table;
            table = nullptr;
            size = 0;
        }
    }

    bool insert(T data) {
        unsigned int index = 0;

        if (!table) {
            return false;
        }

        index = getIndex(data);
        if (!table[index].append(data)) {
            return false;
        }
        return true;
    }
    
    bool remove(T data) {
        if (!table) {
            return false;
        }

        unsigned int index = getIndex(data);
        return table[index].deleteElement(data);
    }

    T *search(T data) {
        unsigned int index = 0;
        
        if (!table) {
            return nullptr;
        }

        index = getIndex(data);
        return (table[index].search(data));
    }

    void print() {
        int biggest = 0;
        
        for (unsigned int i = 0; i < size; i++) {
            int lSize = 0;

            lSize = table[i].getSize();
            cout << "Entry[" << i << "]: " << lSize << endl;
            if (lSize > biggest) {
                biggest = lSize;
            }
        }
        cout << "Biggest was: " << biggest << endl;
    }

    T* getRandomElement() {
        if (!table || size == 0) {
            return nullptr;
        }

        unsigned int randomIndex = rand() % size;

        DoublyLinkedList<T>& list = table[randomIndex];

        unsigned int listSize = list.getSize();
        if (listSize == 0) {
            return nullptr;
        }
        unsigned int randomElementIndex = rand() % listSize;

        DoublyLinkedListNode<T>* current = list.getHead();
        for (unsigned int i = 0; i < randomElementIndex; ++i) {
            current = current->next;
        }

        return &current->data;
    }
};