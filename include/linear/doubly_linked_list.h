#pragma once
/**
 * Doubly Linked List (DLL)
 *
 * Operations:
 *  - push_front:    O(1)
 *  - push_back:     O(1)
 *  - pop_front:     O(1)
 *  - pop_back:      O(1)
 *  - search:        O(n)
 *  - remove(value): O(n)
 *  - size:          O(1)
 *  - empty:         O(1)
 */

#include <stdexcept>
#include <utility>
#include <iostream>

namespace ds {

template <typename T>
class DoublyLinkedList {
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();

        void push_front(const T& value);
        void push_front(T&& value);

        void push_back(const T& value);
        void push_back(T&& value);

        void pop_front();
        void pop_back();

        bool search(const T& value) const;

        void print() const;

        bool empty() const noexcept { return head == nullptr; }
        size_t size() const noexcept { return sz; }

        bool remove(const T& value);

    private:
        struct Node {
            T data;
            Node* next;
            Node* prev;

            Node(const T& d) : data(d), next(nullptr), prev(nullptr) {}
            Node(T&& d) : data(std::move(d)), next(nullptr), prev(nullptr) {}
        };

        Node* head;
        Node* tail;
        size_t sz;

        void clear();
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
    : head(nullptr), tail(nullptr), sz(0) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template <typename T>
void DoublyLinkedList<T>::push_front(const T& value) {
    Node* n = new Node(value);
    n->next = head;
    if (head) head->prev = n;
    head = n;
    if (!tail) tail = n;
    sz++;
}

template <typename T>
void DoublyLinkedList<T>::push_front(T&& value) {
    Node* n = new Node(std::move(value));
    n->next = head;
    if (head) head->prev = n;
    head = n;
    if (!tail) tail = n;
    sz++;
}

template <typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
    Node* n = new Node(value);
    if (!tail) {
        head = tail = n;
    } else {
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
    sz++;
}

template <typename T>
void DoublyLinkedList<T>::push_back(T&& value) {
    Node* n = new Node(std::move(value));
    if (!tail) {
        head = tail = n;
    } else {
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
    sz++;
}

template <typename T>
void DoublyLinkedList<T>::pop_front() {
    if (!head)
        throw std::out_of_range("DLL::pop_front: empty list");

    Node* t = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    delete t;
    sz--;
}

template <typename T>
void DoublyLinkedList<T>::pop_back() {
    if (!tail)
        throw std::out_of_range("DLL::pop_back: empty list");

    Node* t = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    delete t;
    sz--;
}

template <typename T>
bool DoublyLinkedList<T>::search(const T& value) const {
    Node* cur = head;
    while (cur) {
        if (cur->data == value) return true;
        cur = cur->next;
    }
    return false;
}

template <typename T>
bool DoublyLinkedList<T>::remove(const T& value) {
    Node* cur = head;
    while (cur && cur->data != value) cur = cur->next;
    if (!cur) return false;

    if (cur->prev) cur->prev->next = cur->next;
    else head = cur->next;

    if (cur->next) cur->next->prev = cur->prev;
    else tail = cur->prev;

    delete cur;
    sz--;
    return true;
}

template <typename T>
void DoublyLinkedList<T>::clear() {
    while (head) {
        Node* t = head;
        head = head->next;
        delete t;
    }
    head = tail = nullptr;
    sz = 0;
}

template <typename T>
void DoublyLinkedList<T>::print() const {
    Node* cur = head;
    std::cout << "[";
    while (cur) {
        std::cout << cur->data;
        if (cur->next) std::cout << ", ";
        cur = cur->next;
    }
    std::cout << "]\n";
}

}