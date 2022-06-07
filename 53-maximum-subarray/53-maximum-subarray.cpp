class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        // Method 1: using Kadane's Algo
        // can the subarray considered be empty ? No
        // => Edge Case : If all elements are -ve, return biggest -ve number.

//         int biggestNum = nums[0];
//         for(int i=0; i<n; i++){
//             biggestNum = max(biggestNum, nums[i]);
//         }
        
//         if(biggestNum < 0) return biggestNum;
        
        int currentSum = 0;
        int maxSum = INT_MIN;
        for (int i=0; i<n; i++){
            currentSum += nums[i];
            maxSum = max(maxSum, currentSum);
            if(currentSum < 0) currentSum = 0;
        }
        
        return maxSum;
        
        // using DP - TODO
        
        
        // using Divide and Conquer - TODO
        
        
    }
};