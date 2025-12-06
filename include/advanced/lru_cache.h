#pragma once
/**
 * LRU Cache
 *
 * Operations:
 *  - get:    O(1)
 *  - put:    O(1)
 *
 * Implemented with hash map + doubly linked list.
 */

#include <unordered_map>
#include <list>
#include <iostream>

namespace ds {

template <typename K, typename V>
class LRUCache {
public:
    LRUCache(size_t capacity) : capacity(capacity) {}

    V get(const K& key) {
        if (cacheMap.find(key) == cacheMap.end())
            throw std::out_of_range("Key not found");

        // Move key to front (most recently used)
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        return cacheMap[key]->second;
    }

    void put(const K& key, const V& value) { 
        if (cacheMap.find(key) != cacheMap.end()) {
            // Update value and move to front
            cacheMap[key]->second = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        } else {
            // Insert new
            if (cacheList.size() >= capacity) {
                auto last = cacheList.back();
                cacheMap.erase(last.first);
                cacheList.pop_back();
            }
            cacheList.push_front({key, value});
            cacheMap[key] = cacheList.begin();
        }
    }

    void print() const {
        std::cout << "LRUCache [most recent -> least recent]: ";
        for (const auto& pair : cacheList)
            std::cout << "(" << pair.first << "," << pair.second << ") ";
        std::cout << "\n";
    }

private:
    size_t capacity;
    std::list<std::pair<K, V>> cacheList;
    std::unordered_map<K, typename std::list<std::pair<K, V>>::iterator> cacheMap;
};

} 