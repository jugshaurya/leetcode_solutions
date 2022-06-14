class Solution {
public:
    
    int dp[20];
    int helper(int n){
        
        if(n == 0) return 1;

        if(dp[n] != -1) return dp[n];
      
        int ans = 0;
        for(int i=1; i<=n; i++){
            ans += helper(i - 1) * helper(n - i); 
        }
        
        return dp[n] = ans;
    }
        
    int numTrees(int n) {
        memset(dp,-1,sizeof(dp));
        return helper(n);
    }
};