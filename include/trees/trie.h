#pragma once

/**
 * Trie
 *
 * Operations:
 *  - insert
 *  - search
 *  - startsWith
 *
 * Template-based
 */

#include <iostream>
#include <unordered_map>

namespace ds {

class TrieNode {
public:
    bool isEnd;
    std::unordered_map<char, TrieNode*> children;

    TrieNode() : isEnd(false) {}
};

class Trie {
public:
    Trie() { root = new TrieNode(); }
    ~Trie() { clear(root); }

    void insert(const std::string& word);
    bool search(const std::string& word) const;
    bool startsWith(const std::string& prefix) const;

private:
    TrieNode* root;

    void clear(TrieNode* node);
};

void Trie::insert(const std::string& word) {
    TrieNode* node = root;
    for (char c : word) {
        if (node->children.find(c) == node->children.end())
            node->children[c] = new TrieNode();
        node = node->children[c];
    }
    node->isEnd = true;
}

bool Trie::search(const std::string& word) const {
    TrieNode* node = root;
    for (char c : word) {
        if (node->children.find(c) == node->children.end())
            return false;
        node = node->children.at(c);
    }
    return node->isEnd;
}

bool Trie::startsWith(const std::string& prefix) const {
    TrieNode* node = root;
    for (char c : prefix) {
        if (node->children.find(c) == node->children.end())
            return false;
        node = node->children.at(c);
    }
    return true;
}

void Trie::clear(TrieNode* node) {
    if (!node) return;
    for (auto& pair : node->children)
        clear(pair.second);
    delete node;
}

}