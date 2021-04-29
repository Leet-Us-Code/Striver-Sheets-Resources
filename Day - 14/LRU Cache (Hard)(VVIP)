// Hari

class LRUCache {
public:
    // To add and remove ele in constant time O(1) we use linked list and not array as in array,
    // to shift after deletion is O(n) but not needed in LL ( head, tail ptr)
    
    // To check if element is already in cache, use hashmap (store address and value)
    // Hence, traversal also O(1) and not o(n)
    int capacity;
    list<int> recent; // (front) MRU......LRU (back) has the element values
    unordered_map<int, list<int>::iterator> pos; // key->iterator
    unordered_map<int, int> cache; //key->value. key is the memory of the element value
    
    void use(int key){
        if(pos.find(key) != pos.end()){
            // key exists. 
            recent.erase(pos[key]);
        } else if(recent.size() >= capacity){
            //remove LRU
            int old = recent.back();
            recent.pop_back();
            cache.erase(old); pos.erase(old);
        }
        // add new ele to front (MRU) and make it front
        // no need to shift back all elements before adding new ele as we are not using array
        recent.push_front(key);
        pos[key] = recent.begin();
    }
    
    LRUCache(int capacity) { // runs when initialized
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            use(key);
            return cache[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        use(key);
        cache[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
