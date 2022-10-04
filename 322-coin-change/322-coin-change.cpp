class Solution {
public:
    int rec(int index, vector<int>&coins, int amount, vector<vector<int>> &dp){
        if(amount < 0) return 1e9;
        if(amount == 0) return 0;
        if(index == 0) {
            if(amount >= coins[0] and amount % coins[0] == 0) return amount/coins[0];
            else return 1e9;
        }
        
        if(dp[index][amount] != -1) return dp[index][amount];
        
        int ntake = rec(index - 1, coins, amount, dp);
        int take = 1 + rec(index, coins, amount - coins[index], dp);
        return dp[index][amount] = min(ntake,take);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        long long ans = rec(coins.size()-1,coins,amount,dp);
        if(ans == 1e9) return -1;
        else return ans;
    }
};