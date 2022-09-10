class Solution {
public:
    vector<int> arr;
    int n;
    int dp[1001];
    int rec(int target){
        if(target == 0) return 1;
        if(target < 0) return 0;
        
        if(dp[target] != -1) return dp[target];
        
        int ans = 0;
        for(int i =0; i < n; i++){
            ans += rec(target - arr[i]);
        }
        
        return dp[target] = ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        this->arr = nums;
        this->n = arr.size();
        
        memset(dp, -1, sizeof(dp));
        return rec(target);
    }
};