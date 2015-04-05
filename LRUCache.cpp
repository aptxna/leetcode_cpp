/* 
 * LRU Cache
 * 
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 *
 * It should support the following operations: get and set.
 * 
 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 * 
 * set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity,
 *                   it should invalidate the least recently used item before inserting a new item.
 *
 * 参考：
 * http://fisherlei.blogspot.com/2013/11/leetcode-lru-cache-solution.html
 */

class LRUCache{
private:
    struct CacheUnit {
        int key;
        int value;
        CacheUnit(int k, int v): key(k), value(v) {}
    };
    
    list<CacheUnit> listLRU;
    unordered_map<int, list<CacheUnit>::iterator> mapLRU; // list<CacheUnit>::iterator is the position of list
    int cacheSize;
    
    void MoveToHead(int key) {
        auto updateItem = *mapLRU[key]; // auto表示updateItem的类型和*mapLRU[key]的类型一致
        listLRU.erase(mapLRU[key]); // mapLRU[key]的值是key对应的键值映射在list中的位置
        listLRU.push_front(updateItem);
        mapLRU[key] = listLRU.begin();
    }

public:
    LRUCache(int capacity) {
        cacheSize = capacity;
    }
    
    int get(int key) {
        if (mapLRU.find(key) == mapLRU.end())
            return -1;
        
        MoveToHead(key);
        return mapLRU[key]->value;
    }
    
    void set(int key, int value) {
        if (mapLRU.find(key) == mapLRU.end()) {
            if (listLRU.size() >= cacheSize) {
                // if over size, remove from the tail
                mapLRU.erase(listLRU.back().key);
                listLRU.pop_back();
            }
            
            // insert from the head
            CacheUnit newItem(key, value);
            listLRU.push_front(newItem);
            mapLRU[key] = listLRU.begin();
        }
        else {
            // if the key already exist, update the value
            mapLRU[key]->value = value;
            MoveToHead(key);
        }
    }
};