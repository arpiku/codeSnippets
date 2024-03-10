class LRUCache {
private:
    int capacity;
    std::list<std::pair<int,int>> itemsList;
    std::unordered_map<int, std::list<std::pair<int,int>>::iterator> itemsMap;

    void moveToHead(int key, int val) {
        itemsList.erase(itemsMap[key]);
        itemsList.push_front(std::make_pair(key,val));
        itemsMap[key] = itemsList.begin();
    }
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if(itemsMap.find(key) == itemsMap.end())
            return -1;
        
        auto& it = itemsMap[key];
        int value = it->second;
        moveToHead(key,value);
        return value;
    }
    
    void put(int key, int value) {
        if(itemsMap.find(key) != itemsMap.end()) {
            moveToHead(key,value);
            return;
        }
        if(itemsList.size() == capacity) {
            auto lastPair = itemsList.back();
            int lastKey = lastPair.first;
            itemsMap.erase(lastKey);
            itemsList.pop_back();
        }
        itemsList.push_front(std::make_pair(key,value));
        itemsMap[key] = itemsList.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
