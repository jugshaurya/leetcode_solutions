class Solution {
public:
    string s;
    int n;
    // used to memoize the minChanges required to make s[i,...,j] palindrome
    int minCh[101][101];
    // used to memoize the minimal number of characters 
    // required to change to parition into (k + 1) palindromic substrs.
    int dp[101][101];
    
    int minChanges(int i, int j) {
        if(j - i + 1 <= 1) return 0;
        
        if(minCh[i][j] != -1) return minCh[i][j];
        
        int ans = 1e9;
        if(s[i] == s[j]) ans = minChanges(i + 1, j - 1);
        else ans = 1 + minChanges(i + 1, j - 1);
        return  minCh[i][j] = ans;
    }
    
    int rec(int i, int k){
        
        if(i == n and k == 0) return 0;
        if(i == n and k > 0) return 1e9;
        if(i == n and k < 0) return 1e9;
        if(k <= 0) return 1e9;
        
        if(dp[i][k] != -1) return dp[i][k];
        
        int ans = 1e9;
        for (int j = i; j < n; j++) {
            ans = min(ans, minChanges(i, j) + rec(j + 1, k - 1));
        }
        
        return dp[i][k] = ans;
    }
    
    int palindromePartition(string s, int k) {
        this->s = s;
        this->n = s.size();
        
        memset(minCh, -1, sizeof(minCh));
        memset(dp, -1, sizeof(dp));
        
        return rec(0, k);    
    }
};