class Solution {
public:
    string a, b;
    int n, m;
    int dp[505][505];
    
    int rec(int i, int j){
        
        if(i == n) return m - j;
        if(j == m) return n - i;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = 0;
        if(a[i] == b[j]) ans = rec(i + 1, j + 1);
        else ans = 1 + min(rec(i + 1, j), rec(i, j + 1));
        return dp[i][j] = ans;
    }
    
    int minDistance(string word1, string word2) {
        a = word1;
        b = word2;
        n = word1.size();
        m = word2.size();
        
        memset(dp, -1, sizeof(dp));
        return rec(0, 0);        
    }
};