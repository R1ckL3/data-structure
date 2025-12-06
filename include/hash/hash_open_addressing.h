#pragma once

/**
 * Hash Table with Open Addressing
 *
 * Resolves collisions by probing for the next available slot (linear probing).
 *
 * Operations:
 *  - insert:   O(1) average, O(n) worst
 *  - search:   O(1) average, O(n) worst
 *  - remove:   O(1) average, O(n) worst
 *
 */

#include <vector>
#include <optional>
#include <iostream>

namespace ds {

template <typename K, typename V>
class HashOpenAddressing {
public:
    explicit HashOpenAddressing(size_t capacity = 10)
        : keys(capacity), values(capacity), used(capacity, false) {}

    void insert(const K& key, const V& value);
    bool find(const K& key) const;
    void remove(const K& key);
    void print() const;

private:
    std::vector<std::optional<K>> keys;
    std::vector<std::optional<V>> values;
    std::vector<bool> used;

    size_t hash(const K& key) const {
        return std::hash<K>()(key) % keys.size();
    }
};

template <typename K, typename V>
void HashOpenAddressing<K,V>::insert(const K& key, const V& value) {
    size_t idx = hash(key);

    for (size_t i = 0; i < keys.size(); i++) {
        size_t tryIdx = (idx + i) % keys.size();

        if (!used[tryIdx] || !keys[tryIdx].has_value() || keys[tryIdx] == key) {
            keys[tryIdx] = key;
            values[tryIdx] = value;
            used[tryIdx] = true;
            return;
        }
    }
}

template <typename K, typename V>
bool HashOpenAddressing<K,V>::find(const K& key) const {
    size_t idx = hash(key);

    for (size_t i = 0; i < keys.size(); i++) {
        size_t tryIdx = (idx + i) % keys.size();

        if (!used[tryIdx]) return false;
        if (keys[tryIdx].has_value() && keys[tryIdx].value() == key)
            return true;
    }
    return false;
}

template <typename K, typename V>
void HashOpenAddressing<K,V>::remove(const K& key) {
    size_t idx = hash(key);

    for (size_t i = 0; i < keys.size(); i++) {
        size_t tryIdx = (idx + i) % keys.size();

        if (!used[tryIdx]) return;

        if (keys[tryIdx].has_value() && keys[tryIdx].value() == key) {
            keys[tryIdx].reset();
            values[tryIdx].reset();
            return;
        }
    }
}

template <typename K, typename V>
void HashOpenAddressing<K,V>::print() const {
    std::cout << "HashTable (Linear Probing):\n";
    for (size_t i = 0; i < keys.size(); i++) {
        std::cout << "[" << i << "]: ";

        if (!used[i]) {
            std::cout << "EMPTY\n";
        } else if (!keys[i].has_value()) {
            std::cout << "DELETED\n";
        } else {
            std::cout << "(" << keys[i].value() << "," << values[i].value() << ")\n";
        }
    }
}

}