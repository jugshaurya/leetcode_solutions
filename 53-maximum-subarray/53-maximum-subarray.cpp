class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        // Method 1: using Kadane's Algo O(n)
        // int n = nums.size();
        // int currentSum = 0;
        // int maxSum = INT_MIN;
        // for (int i=0; i<n; i++){
        //     currentSum += nums[i];
        //     maxSum = max(maxSum, currentSum);
        //     if(currentSum < 0) currentSum = 0;
        // }
        // return maxSum;
        
        // Method 2: using DP - Kadane's is the space optimized version of this solution
        int n = nums.size();
        int dp[n+1];
        
        // using Divide and Conquer - TODO
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            if(i) dp[i] = nums[i] + max(0, dp[i-1]);
            else dp[i] = nums[i];
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};