class Solution {
public:
    int n, m, l;
    string a, b, c;
    
    int dp[101][101];
    bool rec(int i, int j, int k) {
        
        if(i + j == l and k == l) return true;
        
        if(dp[i][j] != -1) return dp[i][j];
        int ans = false;
        if(j < m and c[k] == b[j]) ans |= rec(i, j + 1, k + 1);
        if(i < n and c[k] == a[i]) ans |= rec(i + 1, j, k + 1);
        return dp[i][j] = ans;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        a = s1;
        b = s2;
        c = s3;
        n = a.size();
        m = b.size();
        l = c.size();
        
        if(n + m != l) return false;
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, 0);
    }
};

// class Solution {
// public:
//     int n, m, l;
//     string a, b, c;
    
//     int dp[101][101][201];
//     bool rec(int i, int j, int k) {
        
//         if(i + j == l and k == l) return true;
        
//         if(dp[i][j][k] != -1) return dp[i][j][k];
//         int ans = false;
//         if(j < m and c[k] == b[j]) ans |= rec(i, j + 1, k + 1);
//         if(i < n and c[k] == a[i]) ans |= rec(i + 1, j, k + 1);
//         return dp[i][j][k] = ans;
//     }
    
//     bool isInterleave(string s1, string s2, string s3) {
//         a = s1;
//         b = s2;
//         c = s3;
//         n = a.size();
//         m = b.size();
//         l = c.size();
        
//         if(n + m != l) return false;
//         memset(dp, -1, sizeof(dp));
//         return rec(0, 0, 0);
//     }
// };