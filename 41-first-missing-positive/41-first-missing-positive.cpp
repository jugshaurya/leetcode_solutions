class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0; i<n; i++) {
            if(nums[i] <= 0)  nums[i] = n + 2;
        }
        
        for(int i=0; i<n; i++) {
            int toUpdateIndex = abs(nums[i]);
            if(toUpdateIndex>=1 and toUpdateIndex<=n) {
                nums[toUpdateIndex - 1] = -(abs(nums[toUpdateIndex - 1]));
            }
        }
        
        for(int i = 1; i <= n; i++) {
            if(nums[i-1] > 0) return i;
        }
        
        return n + 1;
    }
};