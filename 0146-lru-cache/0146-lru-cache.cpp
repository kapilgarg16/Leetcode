class LRUCache {
public:
    list<int>dll;
    unordered_map<int, pair<list<int>::iterator, int>>ump;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    void makeItFirst(int key){
        dll.erase(ump[key].first);
        dll.push_front(key);
        ump[key].first = dll.begin();
    }
    int get(int key) {
        if(ump.find(key) == ump.end())
            return -1;
            
        makeItFirst(key);
        return ump[key].second;
    }
    
    void put(int key, int value) {
        if(ump.find(key) != ump.end()){
            ump[key].second = value;
            makeItFirst(key);
        }
        else{
            dll.push_front(key);
            ump[key] = {dll.begin(), value};
            cap--;
        }
        
        if(cap < 0){
            ump.erase(dll.back());
            dll.pop_back();
            cap++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */