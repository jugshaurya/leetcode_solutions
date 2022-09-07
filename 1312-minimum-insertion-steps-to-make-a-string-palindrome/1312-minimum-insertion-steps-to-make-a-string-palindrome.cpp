// Method2: Direct dp(i, j)
// clas Solution {
// public: 
//     string s;
//     int dp[505][505];
    
//     int rec(int i, int j) {
//         if (i > j) return 0;
//         if (i == j) return 0;

//         if (dp[i][j] != -1) return dp[i][j];
        
//         int ans = 0;
//         if (s[i] == s[j]) ans = rec(i + 1, j - 1);
//         else ans = 1 + min(rec(i, j - 1), rec(i + 1, j));
//         return dp[i][j] = ans;
//     }
    
//     int minInsertions(string s) {
//         this->s = s;

//         memset(dp, -1, sizeof(dp));
//         int n = s.size();
//         return rec(0, n - 1);
//     }
// }

// Method 1: #insertions = #deletions = n - LPS(s)
class Solution {
public:
    string s;
    int dp[505][505];

    int rec(int i, int j) {
        if (i > j) return 0;
        if (i == j) return 1;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int ans = 0 ;
        if (s[i] == s[j]) ans = 2 + rec(i + 1, j - 1);
        else ans = max(rec(i, j - 1), rec(i + 1, j));
            
        
        return dp[i][j] = ans;
    }

    int minInsertions(string s) {
        this->s = s;

        memset(dp, -1, sizeof(dp));
        int n = s.size();
        return n - rec(0, n - 1);
    }
};

