#pragma once

/**
 * Hash Table with Chaining
 *
 * Resolves collisions by storing multiple elements in linked lists at each bucket.
 *
 * Operations:
 *  - insert:   O(1) average, O(n) worst
 *  - search:   O(1) average, O(n) worst
 *  - remove:   O(1) average, O(n) worst
 *
 */

#include <vector>
#include <list>
#include <iostream>
#include <stdexcept>

namespace ds {

template <typename K, typename V>
class HashChaining {
public:
    explicit HashChaining(size_t capacity = 10)
        : table(capacity) {}

    void insert(const K& key, const V& value);
    bool find(const K& key) const;
    void remove(const K& key);
    void print() const;

private:
    std::vector<std::list<std::pair<K,V>>> table;

    size_t hash(const K& key) const {
        return std::hash<K>()(key) % table.size();
    }
};

template <typename K, typename V>
void HashChaining<K,V>::insert(const K& key, const V& value) {
    size_t idx = hash(key);
    for (auto& p : table[idx]) {
        if (p.first == key) {
            p.second = value;
            return;
        }
    }
    table[idx].push_back({key, value});
}

template <typename K, typename V>
bool HashChaining<K,V>::find(const K& key) const {
    size_t idx = hash(key);
    for (const auto& p : table[idx])
        if (p.first == key)
            return true;
    return false;
}

template <typename K, typename V>
void HashChaining<K,V>::remove(const K& key) {
    size_t idx = hash(key);
    table[idx].remove_if([&](const auto& p){ return p.first == key; });
}

template <typename K, typename V>
void HashChaining<K,V>::print() const {
    std::cout << "HashTable (Chaining):\n";
    for (size_t i = 0; i < table.size(); i++) {
        std::cout << "[" << i << "]: ";
        for (const auto& p : table[i])
            std::cout << "(" << p.first << "," << p.second << ") ";
        std::cout << "\n";
    }
}

}