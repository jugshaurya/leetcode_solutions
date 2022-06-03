vector<vector<int>> memo;
class Solution {
    public:
    int helper(string &s, int i, int j) {
        if (i > j) return 0;
        if (i == j) return 1;
        
        if (memo[i][j] != -1) return memo[i][j];
        
        if (s[i] == s[j]) return memo[i][j] = 2 + helper(s, i + 1, j - 1);
        return memo[i][j] = max(helper(s, i, j - 1), helper(s, i + 1, j));
    }

    int longestPalindromeSubseq(string s) {
        int n = s.length();
        memo = vector<vector<int>> (n + 1, vector<int>(n + 1, -1));
        int ans = helper(s, 0, s.size() - 1);
        return ans;
    }
};