// Logic: Every number can possibly become the root.
class Solution {
public:
    int dp[20];
    
    int rec(int n){
        if(n == 0) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans += rec(i - 1) * rec(n - i); 
        }
        
        return dp[n] = ans;
    }
        
    int numTrees(int n) {
        memset(dp, -1, sizeof(dp));
        return rec(n);
    }
};