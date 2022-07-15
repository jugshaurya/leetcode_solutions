class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        // first value store, maximum +ve subarray sum possible.
        // second value store, minimum -ve subarray sum possible, 
        // because minimum of -ve will result in maximum value 
        // if multiplied by -ve number.
        pair<int, int> dp[n+1];
        dp[0] = {nums[0], nums[0]};
        int ans = nums[0];
        
        for(int i = 1; i < n; i++){
            dp[i].first = max({ nums[i], nums[i] * dp[i-1].first, nums[i] * dp[i-1].second});
            dp[i].second = min({ nums[i], nums[i] * dp[i-1].first, nums[i] * dp[i-1].second});
            ans = max({ans, dp[i].first, dp[i].second});
        }
        
        return ans;
    }
};