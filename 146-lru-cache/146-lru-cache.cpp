class LRUCache {
public:
    int capacity;
    int cnt;
    list<int> l;
    unordered_map<int, pair<int, list<int>::iterator>> m;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        cnt=0;
    }
    
    int get(int key) {
        if(m.count(key)){
            list<int>::iterator index = m[key].second;
            l.erase(index);
            l.push_back(key);
            auto it = l.end();
            it--;
            m[key] = {m[key].first, it};
            return m[key].first;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(m.count(key)){
            list<int>::iterator index = m[key].second;
            l.erase(index);
            l.push_back(key);
            auto it = l.end();
            it--;
            m[key] = {value, it};
        }else{
            if(cnt==capacity){
                // replace LRU node with new node
                int frontVal = l.front();
                l.pop_front();
                m.erase(frontVal);
                l.push_back(key);
                auto it = l.end();
                it--;
                m[key] = {value, it};
                return;
            }
            cnt++;
            l.push_back(key);
            auto it = l.end();
            it--;
            m[key] = {value, it};
            return;
        }
    }
};