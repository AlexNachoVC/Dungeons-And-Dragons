#pragma once
#include "Queue.hpp"
#include <cstdlib>
#include <ctime>

using namespace std;
template <typename T>
class TreeNode {
public:
    T info;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) : info(data), left(nullptr), right(nullptr) {}
};

template <typename T>
class BST {
private:
    TreeNode<T> *root;

    T* recursiveSearch(TreeNode<T> *curr, T data) {
        if (!curr) {
            return nullptr;
        }
        if (data < curr->info) {
            return(recursiveSearch(curr->left, data));
        }
        else if (data > curr->info) {
            return(recursiveSearch(curr->right, data));
        }
        return &curr->info;
    }

    bool recursiveInsert(TreeNode<T> *&node, T data) {
        if (!node) {
            node = new(nothrow) TreeNode<T>(data);
            if (!node) {
                return false;
            }
            return true;
        }

        if (data < node->info) {
            return recursiveInsert(node->left, data);
        }
        else if (data > node->info) {
            return recursiveInsert(node->right, data);
        }

        // El dato ya existe en el arbol, no se permite duplicados
        // si deseamos incluir duplicados, cambiar arriba "<" por "<="
        return false;
    }
    void walkInOrder(TreeNode<T>* curr) {
        if (curr == nullptr) {
            return;
        }
        walkInOrder(curr->left);
        cout << curr->info << " ";
        walkInOrder(curr->right);
    }

    void walkPreOrder(TreeNode<T>* curr) {
        if (curr == nullptr) {
            return;
        }
        
        cout << curr->info << " ";
        walkPreOrder(curr->left);
        walkPreOrder(curr->right);
    }

    void walkPostOrder(TreeNode<T>* curr) {
        if (curr == nullptr) {
            return;
        }

        walkPostOrder(curr->left);
        walkPostOrder(curr->right);
        cout << curr->info << " ";
    }

    bool recursiveRemove(TreeNode<T> *& root, T data) {
        if (root == nullptr) {
            return false;
        }
        else if (data < root->info) {
            recursiveRemove(root->left, data);
        }
        else if (data > root->info) {
            recursiveRemove(root->right, data);
        }
        else {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                root = nullptr;
                return true;
            }
            else if (root->left == nullptr) {
                TreeNode<T> *tmp = root;
                root = root->right;
                delete tmp;
                return true;
            }
            else if (root->right == nullptr) {
                TreeNode<T> *tmp = root;
                root = root->left;
                delete tmp;
                return true;
            }
            else {
                TreeNode<T> *tmp = findMin(root->right);
                root->info = tmp->info;
                return recursiveRemove(root->right, tmp->info);
            }
        }
    }

    TreeNode<T>* findMin(TreeNode<T> *root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    void deletePostOrder(TreeNode<T> *curr) {
        if (curr == nullptr) {
            return;
        }
        deletePostOrder(curr->left);
        deletePostOrder(curr->right);
        delete curr;
    }

    int countNodes(TreeNode<T> *node) {
        if (node == nullptr) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    T* getNodeByIndex(TreeNode<T> *node, int index) {
        if (node == nullptr) return nullptr;

        int leftCount = countNodes(node->left);
        if (index < leftCount) {
            return getNodeByIndex(node->left, index);
        } else if (index == leftCount) {
            return &(node->info);
        } else {
            return getNodeByIndex(node->right, index - leftCount - 1);
        }
    }


public:
    BST() {
        root = nullptr;
    }

    ~BST() {
        deleteBST();
    }

    void deleteBST() {
       deletePostOrder(root);
       root = nullptr;
    };

    T* search(T data) {
        return(recursiveSearch(root, data));
    }

    bool insert(T data) {
        return(recursiveInsert(root, data));
    }

    void printInOrder() {
        walkInOrder(root);
        cout << endl;
    }

    void printPreOrder() {
        walkPreOrder(root);
        cout << endl;
    }

    void printPostOrder() {
        walkPostOrder(root);
        cout << endl;
    }

    void remove(T data) {
        recursiveRemove(root, data);
    }

    void bfs() {
        Queue<TreeNode<T>*> queue;
        if (root == nullptr) {
            return;
        }

        queue.enqueue(root);

        while (!queue.isEmpty()) {
            TreeNode<T>** tmp = queue.peek();
            TreeNode<T>* curr = *tmp;
            queue.deque();

            cout << curr->info << " ";

            if (curr->left != nullptr) {
                queue.enqueue(curr->left);
            }
            if (curr->right != nullptr) {
                queue.enqueue(curr->right);
            }
        }
        cout << endl;
    }

    T* getRandomNode() {
        int totalNodes = countNodes(root);
        if (totalNodes == 0) return nullptr;

        int randomIndex = rand() % totalNodes;
        return getNodeByIndex(root, randomIndex);
    }
};