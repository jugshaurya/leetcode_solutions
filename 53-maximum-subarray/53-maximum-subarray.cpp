class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        // using Kadane's Algo
        
        // can the subarray considered be empty ? No
        // => Edge Case : If all elements are -ve, return biggest -ve number.
        bool containsPositive = false;
        int biggestNum = nums[0];
        for(int i=0; i<n; i++){
            biggestNum = max(biggestNum, nums[i]);
            if(nums[i] >= 0) containsPositive = true;
        }
        
        if(not containsPositive) return biggestNum;
        
        int currentSum = 0;
        int maxSum = INT_MIN;
        for (int i=0;i<n;i++){
            currentSum += nums[i];
            if(currentSum < 0) currentSum = 0;
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
        
        // using DP
        
        
        // using Divide and Conquer
        
        
    }
};