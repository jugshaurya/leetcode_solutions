class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int n = nums.size();
      int i = 0;
      int j = 0;
      
      while(i<n and j<n) {
        if(nums[i] != 0) {
          i++;
          j++;
        }
        if(i<n and j<n and nums[i] == 0 and nums[j] == 0) {
          j++;
        }
        if(i<n and j<n and nums[i] == 0 and nums[j] != 0) {
          swap(nums[i], nums[j]);
          i++;
          j++;
        } 
      }
    }
};