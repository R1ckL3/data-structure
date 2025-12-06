#include <iostream>
#include "../../include/trees/trie.h"

void check(bool condition, const std::string& action, const std::string& expected) {
    std::cout << action << " -> Expected: " << expected 
              << ", Actual: " << (condition ? "True" : "False") << "\n";
}

int main() {
    ds::Trie trie;

    std::cout << "--- Inserting words ---\n";
    std::string words[] = {"apple", "app", "banana", "bat", "battle"};
    for (const auto& w : words) {
        std::cout << "Insert: " << w << "\n";
        trie.insert(w);
    }

    std::cout << "\n--- Search tests ---\n";
    check(trie.search("apple"), "Search 'apple'", "True");
    check(trie.search("app"), "Search 'app'", "True");
    check(trie.search("banana"), "Search 'banana'", "True");
    check(trie.search("bat"), "Search 'bat'", "True");
    check(trie.search("battle"), "Search 'battle'", "True");
    check(trie.search("apricot"), "Search 'apricot'", "False");
    check(trie.search("battles"), "Search 'battles'", "False");

    std::cout << "\n--- Prefix tests ---\n";
    check(trie.startsWith("ap"), "Starts with 'ap'", "True");
    check(trie.startsWith("ba"), "Starts with 'ba'", "True");
    check(trie.startsWith("bat"), "Starts with 'bat'", "True");
    check(trie.startsWith("battl"), "Starts with 'battl'", "True");
    check(trie.startsWith("ca"), "Starts with 'ca'", "False");
    check(trie.startsWith("a"), "Starts with 'a'", "True");

    return 0;
}