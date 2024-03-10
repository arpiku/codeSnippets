#include <iostream>
#include <unordered_map>
#include <list>

class LRUCache {
private:
    int capacity;
    std::list<std::pair<int, int>> itemsList; // Stores key-value pairs
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> itemsMap; // Maps key to the iterator in the items list

    void moveToHead(int key, int value) {
        itemsList.erase(itemsMap[key]); // Remove element from its current position
        itemsList.push_front(std::make_pair(key, value)); // Insert element at the beginning
        itemsMap[key] = itemsList.begin(); // Update the reference in the map
    }

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (itemsMap.find(key) == itemsMap.end()) // Key not found
            return -1;

        auto& it = itemsMap[key];
        int value = it->second;
        itemsList.erase(it); // Remove the node
        itemsList.push_front(std::make_pair(key, value)); // Insert it at the beginning
        itemsMap[key] = itemsList.begin(); // Update the map

        return value;
    }

    void put(int key, int value) {
        if (itemsMap.find(key) != itemsMap.end()) { // Key exists
            moveToHead(key, value);
            return;
        }

        if (itemsList.size() == capacity) { // Reached capacity
            auto lastPair = itemsList.back();
            int lastKey = lastPair.first;
            itemsMap.erase(lastKey); // Remove from map
            itemsList.pop_back(); // Remove least recently used element
        }

        itemsList.push_front(std::make_pair(key, value)); // Insert element at the beginning
        itemsMap[key] = itemsList.begin(); // Update the map
    }
};

int main() {
    LRUCache cache(2); // Capacity of the cache

    cache.put(1, 1);
    cache.put(2, 2);
    std::cout << cache.get(1) << std::endl; // returns 1
    cache.put(3, 3);    // evicts key 2
    std::cout << cache.get(2) << std::endl; // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    std::cout << cache.get(1) << std::endl; // returns -1 (not found)
    std::cout << cache.get(3) << std::endl; // returns 3
    std::cout << cache.get(4) << std::endl; // returns 4

    return 0;
}
