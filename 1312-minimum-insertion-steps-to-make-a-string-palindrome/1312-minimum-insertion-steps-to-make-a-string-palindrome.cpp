vector<vector<int>> memo;

class Solution {
public:
    
// ================== Method 1: #insertions = #deletions = n - LPS(s) ==========================
    
//     int LPSHelper(string &s, int i, int j) {
//         if (i > j) return 0;
//         if (i == j) return 1;
        
//         if (memo[i][j] != -1) return memo[i][j];
        
//         if (s[i] == s[j]) return memo[i][j] = 2 + LPSHelper(s, i + 1, j - 1);
//         return memo[i][j] = max(LPSHelper(s, i, j - 1), LPSHelper(s, i + 1, j));
//     }

//     int LPS(string s) {
//         int n = s.length();
//         memo = vector<vector<int>> (n + 1, vector<int>(n + 1, -1));
//         int ans = LPSHelper(s, 0, s.size() - 1);
//         return ans;
//     }
    
//     int minInsertions(string s) {
//         return s.size() - LPS(s);
//     }
    
    
// ================== Method2: direct dp(i,j) ==========================
    int rec(string &s, int i, int j) {
        if (i > j) return 0;
        if (i == j) return 0;
        
        if (memo[i][j] != -1) return memo[i][j];
        
        if (s[i] == s[j]) return memo[i][j] = rec(s, i + 1, j - 1);
        return memo[i][j] = 1 + min(rec(s, i, j - 1), rec(s, i + 1, j));
    }

    int helper(string s) {
        int n = s.length();
        memo = vector<vector<int>> (n + 1, vector<int>(n + 1, -1));
        return rec(s, 0, s.size() - 1);
    }
    
    int minInsertions(string s) {
        // Method 2: #insertions = #deletions = n - LPS(s)
        return helper(s);
    }
};

