# Data Structures Library (C++)

![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)
![C++](https://img.shields.io/badge/C%2B%2B-17-blue)

A clean and organized collection of common **data structures** implemented in modern C++.  
Designed for **learning, competitive programming, and system projects**. Includes tests and example usage.

---

## 🔹 Features

### Linear Structures
- Singly Linked List  
- Doubly Linked List  
- Stack  
- Queue  
- Deque  

### Trees
- Binary Search Tree (BST)  
- AVL Tree  
- Trie  

### Hash Tables
- Hash Table with Chaining  
- Hash Table with Open Addressing  

### Heaps
- Min Heap  
- Max Heap  

### Graphs
- Breadth-First Search (BFS)  
- Depth-First Search (DFS)  
- Graph Representation  

### Advanced
- LRU Cache  
- Union-Find (Disjoint Set)  

---

## 📂 Folder Structure

data-structure/
├── include/           # Header files for all data structures
│   ├── linear/
│   ├── trees/
│   ├── graph/
│   ├── hash/
│   ├── heaps/
│   └── advanced/
├── tests/             # Unit tests for each structure
│   ├── linear/
│   ├── trees/
│   ├── graphs/
│   ├── hash/
│   └── heaps/
├── examples/          # Example usage programs
├── docs/              # Documentation (optional)
├── structure.json     # Automatically generated folder structure
├── README.md
├── LICENSE
└── .gitignore

<details>
<summary>Click to view full JSON structure</summary>

```json
{
  "name": "Data_Structre",
  "type": "directory",
  "children": [
    {
      "name": "structre.py",
      "type": "file"
    },
    {
      "name": "include",
      "type": "directory",
      "children": [
        {
          "name": "advanced",
          "type": "directory",
          "children": [
            { "name": "lru_cache.h", "type": "file" },
            { "name": "union_find.h", "type": "file" }
          ]
        },
        {
          "name": "trees",
          "type": "directory",
          "children": [
            { "name": "bst.h", "type": "file" },
            { "name": "trie.h", "type": "file" },
            { "name": "avl_tree.h", "type": "file" }
          ]
        },
        {
          "name": "hash",
          "type": "directory",
          "children": [
            { "name": "hash_chaining.h", "type": "file" },
            { "name": "hash_open_addressing.h", "type": "file" }
          ]
        },
        {
          "name": "linear",
          "type": "directory",
          "children": [
            { "name": "doubly_linked_list.h", "type": "file" },
            { "name": "singly_linked_list.h", "type": "file" },
            { "name": "deque.h", "type": "file" },
            { "name": "stack.h", "type": "file" },
            { "name": "queue.h", "type": "file" }
          ]
        },
        {
          "name": "graph",
          "type": "directory",
          "children": [
            { "name": "dfs.h", "type": "file" },
            { "name": "bfs.h", "type": "file" },
            { "name": "graph.h", "type": "file" }
          ]
        },
        {
          "name": "heaps",
          "type": "directory",
          "children": [
            { "name": "min_heap.h", "type": "file" },
            { "name": "max_heap.h", "type": "file" }
          ]
        },
        {
          "name": "utils",
          "type": "directory",
          "children": []
        }
      ]
    },
    {
      "name": "tests",
      "type": "directory"
    },
    {
      "name": "docs",
      "type": "directory"
    },
    {
      "name": "examples",
      "type": "directory"
    }
  ]
}
