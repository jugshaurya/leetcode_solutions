class Solution {
public:
    
    int kadane(vector<int> &nums){
        int n = nums.size();
        int dp[n+1];
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            if(i) dp[i] = nums[i] + max(0, dp[i-1]);
            else dp[i] = nums[i];
            ans = max(ans,dp[i]);
        }
        return ans;
    }
    
    int maxAbsoluteSum(vector<int>& nums) {
        
        int ans1 = kadane(nums);
        for(auto &x: nums){
            x = -x;
        }
        int ans2 = kadane(nums);
        return max(abs(ans1), abs(ans2));
        
    }
};