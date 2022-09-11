class Solution {
public:
    set<string> st;
    string s;
    int n;
    int dp[301];
    
    vector<string> ans;
    void rec(int i, string tmp){
        if(i == n) {
            ans.push_back(tmp);
            return;
        }
        
        string old = tmp;
        for(int j = i; j < n; j++) {
            string substring = s.substr(i, j - i + 1);
            if(st.count(substring)) {
                tmp += substring;
                if(j != n - 1) tmp += " ";
                rec(j + 1, tmp);
                tmp = old; 
            }    
        }
    }    
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this->s = s;
        this->n = s.size();
        for(auto x: wordDict) this->st.insert(x);
        
        memset(dp, -1, sizeof(dp));
        string tmp;
        rec(0, tmp);
        return ans;
    }
};