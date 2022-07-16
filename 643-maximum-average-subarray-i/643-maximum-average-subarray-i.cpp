class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        
        double sum = 0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        
        double ans = sum;
        for(int i = k; i < n; i++){
            sum += nums[i];
            sum -= nums[i - k];
            ans = max(ans, sum);
        }
        
        return ans / k; 
    }
};