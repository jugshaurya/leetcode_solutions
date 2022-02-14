class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // find the mean and bring every number to it.
        
        sort(nums.begin(), nums.end());
        int mean = nums[nums.size()/2];
        int ans = 0;
        for(auto x: nums){
            ans += abs(mean-x);
        }
        
        return ans;
    }
};