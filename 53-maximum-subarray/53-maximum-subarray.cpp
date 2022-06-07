struct ReturnType{
    
    int ms; // maximum subarray sum
    int mps; // maximum prefix sum
    int mss; // maximum suffix sum
    int ts; // total sum
};

class Solution {
public:
    
    ReturnType helper(vector<int> & nums, int start, int end){
        if(start == end){
            return {nums[start],nums[start],nums[start],nums[start]};
        }
        
        int mid = (start + end)/2;
        ReturnType left = helper(nums, start, mid);
        ReturnType right = helper(nums, mid+1, end);
        
        ReturnType ans;
        ans.ms = max({left.ms, right.ms, left.mss, right.mps, left.mss + right.mps});
        ans.mps = max(left.mps, left.ts + right.mps);
        ans.mss = max(right.mss, right.ts + left.mss);
        ans.ts = left.ts + right.ts;
        return ans;
    }
    
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
        // int n = nums.size();
        // int dp[n+1];
        
        // int ans = INT_MIN;
        // for(int i=0;i<n;i++){
        //     if(i) dp[i] = nums[i] + max(0, dp[i-1]);
        //     else dp[i] = nums[i];
        //     ans = max(ans,dp[i]);
        // }
        // return ans;
        
        // Method 3: using Divide and Conquer 
        int n = nums.size();
        return helper(nums, 0, n - 1).ms;
    }
};