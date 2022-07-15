class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        // Logic: start from the back and keep on taking max
        int n = nums.size();
        int maxx = nums[n-1];
        
        int ans = -1;
        for(int i = n-2; i>=0; i--){
            ans = max(ans, maxx - nums[i]);
            maxx = max(maxx, nums[i]);
        }
        
        return ans <= 0 ? -1 : ans;
    }
};