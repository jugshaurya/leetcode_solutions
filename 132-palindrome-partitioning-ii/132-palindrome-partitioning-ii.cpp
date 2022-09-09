class Solution {
public:
    string s;
    int n;
    int dp[2002];
    
    bool isPalindrome(int i, int j) {
        if(i >= j) return true;    
        return s[i] == s[j] and isPalindrome(i + 1, j - 1); 
    }
    
    int rec (int i) {
        if(i == n) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int ans = 1e9;
        for(int j = i; j < n; j++){
            if(isPalindrome(i, j)) {
                ans = min(ans, 1 + rec(j + 1));
            }
        }
        
        return dp[i] = ans;
    }
    
    int minCut(string s) {
        this->s = s;
        this->n = s.size();
        
        memset(dp, -1, sizeof(dp));
        return rec(0) - 1;
    }
};

