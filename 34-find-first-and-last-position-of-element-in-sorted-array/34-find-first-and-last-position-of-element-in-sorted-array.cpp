
class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
      
      vector<int> ans;
      int n = nums.size();

      int start = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
      if(start == n) return ans = {-1,-1};
      
      int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin(); 
      if(nums[start] == target) return ans = {start,end-1};
      return ans = {-1,-1};
  }
};
