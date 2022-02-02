class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        for(int i =0;i<(int)nums.size(); i++){
            nums[i] += i==0 || nums[i]==0 ? 0: nums[i-1]; 
        }
        
        return *max_element(nums.begin(), nums.end());
    }
};