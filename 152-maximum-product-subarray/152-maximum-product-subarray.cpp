class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        pair<int,int> dp[n+1];
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            if(i) {
                dp[i].first = max({nums[i], nums[i] *dp[i-1].first, nums[i]*dp[i-1].second});
                dp[i].second = min({nums[i], nums[i] *dp[i-1].first, nums[i]*dp[i-1].second});
            }
            else dp[i] = {nums[i], nums[i]};
            ans = max({ans,dp[i].first, dp[i].second});
        }
        return ans;
    }
};