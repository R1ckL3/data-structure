#include "../../include/advanced/lru_cache.h"
#include <iostream>

int main() {
    std::cout << "--- Testing LRUCache<int,int> ---\n";

    ds::LRUCache<int,int> cache(3);

    std::cout << "Put (1,100), (2,200), (3,300)\n";
    cache.put(1,100);
    cache.put(2,200);
    cache.put(3,300);
    cache.print();
    std::cout << "Expected: (3,300) (2,200) (1,100)\n\n";

    std::cout << "Access key 2\n";
    cache.get(2);
    cache.print();
    std::cout << "Expected: (2,200) (3,300) (1,100)\n\n";

    std::cout << "Add key 4 -> should evict least recently used (1)\n";
    cache.put(4,400);
    cache.print();
    std::cout << "Expected: (4,400) (2,200) (3,300)\n\n";

    std::cout << "Access key 3\n";
    cache.get(3);
    cache.print();
    std::cout << "Expected: (3,300) (4,400) (2,200)\n\n";

    return 0;
}