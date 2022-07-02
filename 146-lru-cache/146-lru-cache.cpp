// Method2: using STL's list
// class LRUCache {
// public:
//     int capacity;
//     int cnt;
//     list<int> l;
//     unordered_map<int, pair<int, list<int>::iterator>> m;
    
//     LRUCache(int capacity) {
//         this->capacity = capacity;
//         cnt=0;
//     }
    
//     int get(int key) {
//         if(m.count(key)){
//             list<int>::iterator index = m[key].second;
//             l.erase(index);
//             l.push_back(key);
//             auto it = l.end();
//             it--;
//             m[key] = {m[key].first, it};
//             return m[key].first;
//         }else{
//             return -1;
//         }
//     }
    
//     void put(int key, int value) {
//         if(m.count(key)){
//             list<int>::iterator index = m[key].second;
//             l.erase(index);
//             l.push_back(key);
//             auto it = l.end();
//             it--;
//             m[key] = {value, it};
//         }else{
//             if(cnt==capacity){
//                 // replace LRU node with new node
//                 int frontVal = l.front();
//                 l.pop_front();
//                 m.erase(frontVal);
//                 l.push_back(key);
//                 auto it = l.end();
//                 it--;
//                 m[key] = {value, it};
//                 return;
//             }
//             cnt++;
//             l.push_back(key);
//             auto it = l.end();
//             it--;
//             m[key] = {value, it};
//             return;
//         }
//     }
// };


// Method 1: using list from scratch
// will give TLE.
struct Node{
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int key, int value): key(key), value(value), next(NULL), prev(NULL){}
};

class LRUCache {
public:
    
    Node* head;
    Node* tail;
    int capacity;
    int sz;
    map<int, pair<int, Node*>> mp;
    
    LRUCache(int capacity) {
        this->capacity = capacity;  
        head = tail = NULL;
        sz = 0;
    }
    
    void shiftNodeToFront(Node* node) {
        if(node->prev == NULL) return;
        if(node->next == NULL) {
            tail = node->prev;
            node->prev->next = NULL;
            node->prev = NULL;
            node->next = head;
            head->prev = node;
            head = node;
            return;
        }
        
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = head;
        head->prev = node;
        node->prev = NULL;
        head = node;
    }
    
    int get(int key) {
        if(mp.count(key) == 0) return -1;
        shiftNodeToFront(mp[key].second);
        
        return head->value;
    }
    
    // put in front if used latest
    // => least recenlty used will be at back
    void put(int key, int value) {
        if(mp.count(key) == 1) {
            shiftNodeToFront(mp[key].second);
            mp[key].first = value;
            mp[key].second->value = value;
            return;
        }
        
        if(sz == capacity){
            // remove the last Node
            Node* tmp = tail;
            if(tail->prev == NULL) {
                head = tail = NULL;
            }else{
                tail = tail->prev;
                tail->next = NULL;
            }
            mp.erase(tmp->key);
            delete tmp;
            // put the new Node at front and in map
            Node* newNode = new Node(key, value);
            if(head == NULL){
                head = tail = newNode;
            }else{
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            mp[key] = {value, newNode};
        }else{
            // we have space to add in cache
            // push into the front
            sz++;
            Node* newNode = new Node(key, value);
            if(head == NULL) {
                head = tail = newNode;
            }else{
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            mp[key] = {value, newNode};
        }
    }
};
