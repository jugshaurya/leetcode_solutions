class Solution {
public:
    int fib(int n) {
    //=============Bottom up======================
    vector<int> dp(n+2, 0);
    dp[1] = 1;
    for (int i = 2; i<=n; i++){
       dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];

    //============= Space Optimized ======================

    int a = 1, b = 2;
    int c = 0;
    for (int i = 3; i <= n; i++) {
      c = a + b;
      a = b;
      b = c;
    }

    return n == 1 ? 1 : (n == 2 ? 2 : c); 
    }
};