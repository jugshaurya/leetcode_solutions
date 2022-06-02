class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
    
        // Recurrence Relation
        // dp(i) = min cost to reach ith index
        // dp(i) = min(cost[i-1] + dp(i-1) , cost[i-2] + dp(i-2))
        // dp(0) = 0
        // dp(1) = 0
        // ans is dp(n)
        
        //=============Bottom up======================
        // int n = cost.size();
        // vector<int> dp(n+1, 0);
        // for (int i = 2; i<=n; i++){
        //    dp[i] = min(cost[i-1] + dp[i-1] , cost[i-2] + dp[i-2]);
        // }
        
        // return dp[n];
        
        
        //============= Space Optimized ======================
        int n = cost.size();
        int a = 0, b = 0;
        int c = 0 ;
        for (int i = 2; i <= n; i++) {
            c = min(cost[i-1] + b , cost[i-2] + a);
            a = b;
            b = c;
        }
        
        return c;
    }
};