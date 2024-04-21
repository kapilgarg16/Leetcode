class RandomizedSet {
        vector<int>v;
        unordered_map<int,int>ump;
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(ump.find(val) != ump.end())
            return false;
        
        v.push_back(val);
        ump[val] = v.size()-1;
        return true;
        
    }
    
    bool remove(int val) {
        if(ump.find(val) == ump.end())
            return false;
        
        int idx = ump[val];
        int lastEle = v.back();
        
        v.back() = val;
        v[idx] = lastEle;
        ump[lastEle] = idx;
        
        ump.erase(val);
        v.pop_back();
        return true;
        
        
    }
    
    int getRandom() {

        int n = v.size();
        if(n == 0)
            return -1;
        int rend = rand()%n;
        return v[rend];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */