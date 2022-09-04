
class Solution {
    public:
    int dp[1001][1001];
    string s;
    
    int rec(int i, int j) {
        if (i > j) return 0;
        if (i == j) return 1;

        if (dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        if (s[i] == s[j]) ans = 2 + rec(i + 1, j - 1);
        else ans = max(rec(i, j - 1), rec(i + 1, j));
        
        return dp[i][j] = ans;
    }

    int longestPalindromeSubseq(string s) {
        this->s = s;
        memset(dp, -1, sizeof(dp));
        int n = s.size();
        return rec(0, n - 1);
    }
};