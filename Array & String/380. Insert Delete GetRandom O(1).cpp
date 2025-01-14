class RandomizedSet {
private:
    vector<int> arr;
    unordered_map<int,int> map;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if(map.find(val) != map.end()) return false;
        else {
            arr.push_back(val);
            map[val] = arr.size()-1;
        }
        return true;
    }
    
    bool remove(int val) {
        if(map.find(val) == map.end()) return false;

        int lastVal = arr.back();
        int index = map[val];
        arr[index] = lastVal;
        map[lastVal] = index;

        arr.pop_back();
        map.erase(val);
        return true;
    }
    
    int getRandom() {
        int ind = rand() % arr.size();
        return arr[ind];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
