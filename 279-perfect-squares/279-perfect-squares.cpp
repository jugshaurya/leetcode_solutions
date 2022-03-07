class Solution {
public:
    int dp[10010];
    
    int helper(int n) {
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int minn = 1e5;
        for(int i=1;i*i<=n;i++){
            minn = min(minn, 1 + helper(n-i*i));
        }
        
        return dp[n] = minn;
    }
    
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        return helper(n);
    }
};