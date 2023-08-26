class RandomizedSet {
public:

    vector<int> vec;
    map<int, int> map;

    RandomizedSet() {
        vec.clear();
        map.clear();
    }
    
    bool insert(int val) {
        if (map.find(val) != map.end()) {
            return false;
        }

        cout<<val<<" "<<vec.size()<<endl;
        map[val] = vec.size();
        vec.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (map.find(val) == map.end()) {
            return false;
        }

        int lastElement = vec.back();
        int idx = map[val];

        cout<<lastElement<< " " << idx<<endl;

        // replacing last element with remove element
        vec[idx] = lastElement;
        map[lastElement] = idx;

        // removing last element from map and vector
        vec.pop_back();
        map.erase(val);

        return true;
    }
    
    int getRandom() {
        return vec.at(rand() % vec.size());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
