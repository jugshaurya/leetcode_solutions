struct TrieNode{
    int val;
    TrieNode* left;  
    TrieNode* right;  
    TrieNode(int val): val(val) , left(NULL) , right(NULL){}
};

struct Trie{
    TrieNode* root;
    Trie(){
        root = new TrieNode(1);
    }
    
    void insert(int val){
        TrieNode* temp = root;
        for(int i=30;i>=0;i--){
            int bit = val & (1<< i);
            if(bit){
                if(!temp->right) temp->right = new TrieNode(val);
                temp = temp->right;
            }else{
                if(!temp->left) temp->left = new TrieNode(val);
                temp = temp->left;
            }
        }
    }
    
    int getMaxXorPossible(int val) {
        TrieNode* temp = root;
        int ans = 0;
        for(int i=30;i>=0;i--){
            int bit = val & (1<< i);
            if(bit) {
                if(temp->left) {
                    temp = temp->left;
                }else{
                    temp = temp->right;
                }
            }else {
                if(temp->right) {
                    temp = temp->right;
                }else{
                    temp = temp->left;
                }
            }
            ans = temp->val;
        } 
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        Trie t;
        t.insert(nums[0]);
        for(int i=1;i<n;i++){
            ans = max(ans, nums[i] ^ t.getMaxXorPossible(nums[i]));
            t.insert(nums[i]);
        }
        return ans;
    }
};