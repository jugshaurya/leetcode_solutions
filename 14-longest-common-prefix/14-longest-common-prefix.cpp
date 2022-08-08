// Logic 1: Keep on finding LCP of two strings
// Logic 2: sort strings and find LCP pof first & last string
// Logic 3: Build PrefixTree(Trie) 


// Using Trie
struct TrieNode{
    vector<TrieNode*> dict;
    bool isTerminal;
    TrieNode() {
        dict = vector<TrieNode*>(26, NULL);
        isTerminal = false;
    }
};

struct Trie {
    TrieNode* root;
    
    Trie(){
        root = new TrieNode();
    }
    
    void insertWord(string word){
        TrieNode* cur = root;
        
        for(auto x: word){
            int idx = x - 'a'; 
            if(cur->dict[idx] == NULL){
                cur->dict[idx] = new TrieNode();
                cur = cur->dict[idx];
            }else{
                cur = cur->dict[idx];
            }
        }
        
        // denoting the terminal, if val is not empty.
        cur->isTerminal = true;
    }
    
    string LCP(){
        TrieNode* cur = root;
        string ans;
        
        while(cur){
            int cnt = 0;
            int digit = -1;
            int i=0;
            for(auto x: cur->dict){
                if(x != NULL) {
                    digit = i;     
                    cnt++;
                }
                i++;
            }
            
            if(cnt != 1 or cur->isTerminal) return ans;
            // => cnt is 1 and cur is non terminal
            ans += (digit + 'a');
            cur = cur->dict[digit];
        }
        
        return ans;
    }
};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie t;
        for(auto x: strs) t.insertWord(x);
        return t.LCP();
    }
};