
struct TrieNode{
    bool isTerminal;
    vector<TrieNode*> mp; 
    
    TrieNode() {
        mp = vector<TrieNode*>(26, NULL);
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        
        for(auto ch: word){
            int idx = ch - 'a';
            if(cur->mp[idx] == NULL) cur->mp[idx] = new TrieNode();
            cur = cur->mp[idx];
        }
        
        cur->isTerminal = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(auto ch: word){
            int idx = ch - 'a';
            if(cur->mp[idx] == NULL) return false;
            cur = cur->mp[idx];
        }
        
        return cur->isTerminal;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(auto ch: prefix){
            int idx = ch - 'a';
            if(cur->mp[idx] == NULL){
                return false;
            }
            cur = cur->mp[idx];
        }
        return true; 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */