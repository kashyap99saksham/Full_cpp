// Approach is to use a queue(implemented using doubly linked list(list in STL)). and it has some fixed size.  and also one hashmap which will save key and address of that node
// when we going to refer to a page if this page exist then we bring that node to the front of queue and return its value. if it is not present them simply add that to front.
// and in inserting page if list is not full then insert at front and if list is full then remove the node from last and then insert at front.

// Code
class LRUCache {
    list<int> cache;
    unordered_map<int, pair<int, list<int>::iterator> > mp;
    int csize;
public:
    LRUCache(int capacity) {
        csize=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        cache.erase(mp[key].second);
        cache.push_front(key);
        mp[key].second=cache.begin();
        return mp[key].first;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            // key found
            cache.erase(mp[key].second);
            
        } else {
            // key not found
            if(csize==cache.size()){
                int last=cache.back();
                cache.pop_back();
                mp.erase(last);
                
            }
        }
        cache.push_front(key);
        mp[key]={value, cache.begin()};
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
