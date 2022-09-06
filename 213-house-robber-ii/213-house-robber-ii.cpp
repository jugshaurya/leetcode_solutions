class Solution {
public:
    vector<int> arr;
    int rob1(int l, int r){
        int n = r - l + 1;
        int dp[n + 1];
        
        dp[0] = 0;
        dp[1] = arr[l];

        for(int i = 2; i <= n; i++) {
            dp[i] = max(arr[l + i - 1] + dp[i - 2], dp[i - 1]);
        }
        return dp[n];
    }

    int rob(vector<int>& nums) {
        arr = nums;
        int n = nums.size();
        if(n == 1) return nums[0];
        
        // Case 1: assuming house 0 will always never be in answer.
        // Case 2: assuming house (n-1) will never be in answer.
        return max(rob1(1, n - 1), rob1(0, n - 2));
    }
};