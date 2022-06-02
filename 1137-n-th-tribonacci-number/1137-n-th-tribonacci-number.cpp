
class Solution {
  public:
  int tribonacci(int n) {
      
    //=============Bottom up======================
    // if (n < 2) return n;
    // if (n == 2) return 1;
    // vector<int> dp(n+1, 0);
    // dp[1] = 1;
    // dp[2] = 1;
    // for (int i = 3; i<=n; i++){
    //    dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    // }
    // return dp[n];

    //============= Space Optimized ======================
    
    if (n < 2) return n;
    if (n == 2) return 1;
      
    int a = 0, b = 1, c = 1;
    int d = 0;
    for (int i = 3; i <= n; i++) {
      d = a + b + c;
      a = b;
      b = c;
      c = d;
    }
    
    return d;
  }
};
