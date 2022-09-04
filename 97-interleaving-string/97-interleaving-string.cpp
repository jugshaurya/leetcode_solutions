class Solution {
public:
    
    bool isInterleave(string s1, string s2, string s3) {
        string a = s1;
        string b = s2;
        string c = s3;
        int n = a.size();
        int m = b.size();
        int l = c.size();
        
        if(n + m != l) return false;
        int dp[2][m + 1];
        for(int i = n; i >= 0; i--) {
            for(int j = m; j >= 0; j--) {
                int k = i + j;
                if(i + j == l and k == l) dp[i&1][j] = true;
                else {
                    dp[i&1][j] = false;
                    if(c[k] == b[j]) dp[i&1][j] |= dp[i&1][j + 1];
                    if(c[k] == a[i]) dp[i&1][j] |= dp[(i + 1)&1][j];
                }
            }
        }
        
        return dp[0][0];
    }
};

// class Solution {
// public:
//     int n, m, l;
//     string a, b, c;
    
//     int dp[101][101];
//     bool rec(int i, int j) {
//         int k = i + j;
        
//         if(i + j == l and k == l) return true;
        
//         if(dp[i][j] != -1) return dp[i][j];
        
//         int ans = false;
//         if(j < m and c[k] == b[j]) ans |= rec(i, j + 1);
//         if(i < n and c[k] == a[i]) ans |= rec(i + 1, j);
//         return dp[i][j] = ans;
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
//         return rec(0, 0);
//     }
// };

// class Solution {
// public:
//     int n, m, l;
//     string a, b, c;
    
//     int dp[101][101];
//     bool rec(int i, int j, int k) {
        
//         if(i + j == l and k == l) return true;
        
//         if(dp[i][j] != -1) return dp[i][j];
//         int ans = false;
//         if(j < m and c[k] == b[j]) ans |= rec(i, j + 1, k + 1);
//         if(i < n and c[k] == a[i]) ans |= rec(i + 1, j, k + 1);
//         return dp[i][j] = ans;
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