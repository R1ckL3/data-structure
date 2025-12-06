#pragma once
/**
 * AVL Tree
 * Self-balancing Binary Search Tree
 */

#include <iostream>

namespace ds {

template <typename T>
struct AVLNode {
    T data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(const T& val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

template <typename T>
class AVL {
public:
    AVL() : root(nullptr) {}
    ~AVL() { clear(root); }

    void insert(const T& value);
    bool search(const T& value) const;
    void remove(const T& value);
    void inorder() const;

private:
    AVLNode<T>* root;

    int height(AVLNode<T>* node) const;
    int balanceFactor(AVLNode<T>* node) const;
    AVLNode<T>* rotateRight(AVLNode<T>* y);
    AVLNode<T>* rotateLeft(AVLNode<T>* x);
    AVLNode<T>* insertNode(AVLNode<T>* node, const T& value);
    AVLNode<T>* removeNode(AVLNode<T>* node, const T& value);
    AVLNode<T>* findMin(AVLNode<T>* node) const;
    void inorderTraversal(AVLNode<T>* node) const;
    void clear(AVLNode<T>* node);
};

template <typename T>
int AVL<T>::height(AVLNode<T>* node) const {
    return node ? node->height : 0;
}

template <typename T>
int AVL<T>::balanceFactor(AVLNode<T>* node) const {
    return node ? height(node->left) - height(node->right) : 0;
}

template <typename T>
AVLNode<T>* AVL<T>::rotateRight(AVLNode<T>* y) {
    AVLNode<T>* x = y->left;
    AVLNode<T>* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

template <typename T>
AVLNode<T>* AVL<T>::rotateLeft(AVLNode<T>* x) {
    AVLNode<T>* y = x->right;
    AVLNode<T>* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

template <typename T>
AVLNode<T>* AVL<T>::insertNode(AVLNode<T>* node, const T& value) {
    if (!node) return new AVLNode<T>(value);

    if (value < node->data)
        node->left = insertNode(node->left, value);
    else if (value > node->data)
        node->right = insertNode(node->right, value);
    else
        return node; // duplicate values not allowed

    node->height = 1 + std::max(height(node->left), height(node->right));
    int bf = balanceFactor(node);

    // Left Left Case
    if (bf > 1 && value < node->left->data)
        return rotateRight(node);

    // Right Right Case
    if (bf < -1 && value > node->right->data)
        return rotateLeft(node);

    // Left Right Case
    if (bf > 1 && value > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (bf < -1 && value < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

template <typename T>
void AVL<T>::insert(const T& value) {
    root = insertNode(root, value);
}

template <typename T>
AVLNode<T>* AVL<T>::findMin(AVLNode<T>* node) const {
    while (node && node->left) node = node->left;
    return node;
}

template <typename T>
AVLNode<T>* AVL<T>::removeNode(AVLNode<T>* node, const T& value) {
    if (!node) return nullptr;

    if (value < node->data)
        node->left = removeNode(node->left, value);
    else if (value > node->data)
        node->right = removeNode(node->right, value);
    else {
        // Node found
        if (!node->left || !node->right) {
            AVLNode<T>* temp = node->left ? node->left : node->right;
            delete node;
            return temp;
        } else {
            AVLNode<T>* temp = findMin(node->right);
            node->data = temp->data;
            node->right = removeNode(node->right, temp->data);
        }
    }

    if (!node) return node;

    node->height = 1 + std::max(height(node->left), height(node->right));
    int bf = balanceFactor(node);

    // Left Left
    if (bf > 1 && balanceFactor(node->left) >= 0) return rotateRight(node);

    // Left Right
    if (bf > 1 && balanceFactor(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Right
    if (bf < -1 && balanceFactor(node->right) <= 0) return rotateLeft(node);

    // Right Left
    if (bf < -1 && balanceFactor(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

template <typename T>
void AVL<T>::remove(const T& value) {
    root = removeNode(root, value);
}

template <typename T>
bool AVL<T>::search(const T& value) const {
    AVLNode<T>* current = root;
    while (current) {
        if (value == current->data) return true;
        else if (value < current->data) current = current->left;
        else current = current->right;
    }
    return false;
}

template <typename T>
void AVL<T>::inorderTraversal(AVLNode<T>* node) const {
    if (!node) return;
    inorderTraversal(node->left);
    std::cout << node->data << " ";
    inorderTraversal(node->right);
}

template <typename T>
void AVL<T>::inorder() const {
    inorderTraversal(root);
    std::cout << "\n";
}

template <typename T>
void AVL<T>::clear(AVLNode<T>* node) {
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
}

}