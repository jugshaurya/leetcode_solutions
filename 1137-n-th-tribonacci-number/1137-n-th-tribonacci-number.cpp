class Solution {
public:
    int tribonacci(int n) {
        //=============Bottom up======================
        vector<int> dp(n+3, 0);
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i<=n; i++){
           dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];

        //============= Space Optimized ======================

//         int a = 0, b = 1;
//         int c = 0;
//         for (int i = 2; i <= n; i++) {
//           c = a + b;
//           a = b;
//           b = c;
//         }
        
//         if(n<2) return n;
//         return c; 
    }
};