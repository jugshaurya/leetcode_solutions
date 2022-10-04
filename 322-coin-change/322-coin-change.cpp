class Solution {
public:
    vector<int> arr;
    int dp[13][10005];
        
    int rec(int i, int amount) {
        if(amount < 0) return 1e9;
        if(amount == 0) return 0;
        if(i == -1) return 1e9;

        if(dp[i][amount] != -1) return dp[i][amount];
        
        int ntake = rec(i - 1, amount);
        int take = 1 + rec(i, amount - arr[i]);
        return dp[i][amount] = min(ntake, take);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        arr = coins;
        int n = coins.size();
        memset(dp, -1, sizeof(dp));
        int ans = rec(n - 1, amount);
        return ans == 1e9 ? -1 : ans;
    }
};