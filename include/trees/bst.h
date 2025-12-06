#pragma once
/**
 * Binary Search Tree (BST)
 *
 * Operations:
 *  - insert: O(log n) average
 *  - search: O(log n) average
 *  - remove: O(log n) average
 *
 */

#include <iostream>
#include <memory>

namespace ds {

template <typename T>
struct BSTNode {
    T data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(const T& val) : data(val), left(nullptr), right(nullptr) {}
};

template <typename T>
class BST {
public:
    BST() : root(nullptr) {}
    ~BST() { clear(root); }

    void insert(const T& value);
    bool search(const T& value) const;
    void remove(const T& value);

    void inorder() const;

private:
    BSTNode<T>* root;

    void clear(BSTNode<T>* node);
    BSTNode<T>* removeNode(BSTNode<T>* node, const T& value);
    BSTNode<T>* findMin(BSTNode<T>* node) const;
    void inorderTraversal(BSTNode<T>* node) const;
};

template <typename T>
void BST<T>::insert(const T& value) {
    BSTNode<T>* newNode = new BSTNode<T>(value);
    if (!root) {
        root = newNode;
        return;
    }
    BSTNode<T>* current = root;
    BSTNode<T>* parent = nullptr;
    while (current) {
        parent = current;
        if (value < current->data)
            current = current->left;
        else
            current = current->right;
    }
    if (value < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

template <typename T>
bool BST<T>::search(const T& value) const {
    BSTNode<T>* current = root;
    while (current) {
        if (value == current->data) return true;
        else if (value < current->data) current = current->left;
        else current = current->right;
    }
    return false;
}

template <typename T>
BSTNode<T>* BST<T>::findMin(BSTNode<T>* node) const {
    while (node && node->left) node = node->left;
    return node;
}

template <typename T>
BSTNode<T>* BST<T>::removeNode(BSTNode<T>* node, const T& value) {
    if (!node) return nullptr;

    if (value < node->data)
        node->left = removeNode(node->left, value);
    else if (value > node->data)
        node->right = removeNode(node->right, value);
    else {
        if (!node->left) {
            BSTNode<T>* rightChild = node->right;
            delete node;
            return rightChild;
        } else if (!node->right) {
            BSTNode<T>* leftChild = node->left;
            delete node;
            return leftChild;
        } else {
            BSTNode<T>* minNode = findMin(node->right);
            node->data = minNode->data;
            node->right = removeNode(node->right, minNode->data);
        }
    }
    return node;
}

template <typename T>
void BST<T>::remove(const T& value) {
    root = removeNode(root, value);
}

template <typename T>
void BST<T>::inorderTraversal(BSTNode<T>* node) const {
    if (!node) return;
    inorderTraversal(node->left);
    std::cout << node->data << " ";
    inorderTraversal(node->right);
}

template <typename T>
void BST<T>::inorder() const {
    inorderTraversal(root);
    std::cout << "\n";
}

template <typename T>
void BST<T>::clear(BSTNode<T>* node) {
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
}

}