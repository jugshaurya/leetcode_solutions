vector<vector<int>> memo;

class Solution {
public:
    
    // for Method1
    int LPSHelper(string &s, int i, int j) {
        if (i > j) return 0;
        if (i == j) return 1;
        
        if (memo[i][j] != -1) return memo[i][j];
        
        if (s[i] == s[j]) return memo[i][j] = 2 + LPSHelper(s, i + 1, j - 1);
        return memo[i][j] = max(LPSHelper(s, i, j - 1), LPSHelper(s, i + 1, j));
    }

    // for Method1
    int LPS(string s) {
        int n = s.length();
        memo = vector<vector<int>> (n + 1, vector<int>(n + 1, -1));
        int ans = LPSHelper(s, 0, s.size() - 1);
        return ans;
    }
    
    int minInsertions(string s) {
        // Method 1: #insertions = #deletions = n - LPS(s)
        return s.size() - LPS(s);
    }
};

