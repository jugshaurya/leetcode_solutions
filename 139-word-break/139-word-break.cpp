// can use trie as well
class Solution {
public:
    set<string> st;
    string s;
    int n;
    int dp[301];
    
    bool rec(int i) {
        if(i == n) return true;
        if(dp[i] != -1) return dp[i];  
        
        for(int j = i; j < n; j++){
            string tmp = s.substr(i, j - i + 1);
            if(st.count(tmp)) {
                if(rec(j + 1)) return dp[i] = true;
            }
        }
        
        return dp[i] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        this->s = s;
        this->n = s.size();
        for(auto x: wordDict) this->st.insert(x);
        
        memset(dp, -1, sizeof(dp));
        return rec(0);
        
    }
};