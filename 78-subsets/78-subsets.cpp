class Solution {
public:
    vector<vector<int>> subsetsMethod1(vector<int>& nums, int i=0) {
      vector<vector<int> > ans;
      if(i==nums.size()) {ans.push_back(vector<int>()); return ans;} 
      vector<vector<int>> v =  subsets(nums,i+1);
      for(auto x: v) ans.push_back(x); 
      for(auto x: v) {
        x.push_back(nums[i]);
        reverse(x.begin(), x.end());
        ans.push_back(x);
      } 
      
      return ans;
    }
  
    //     Method 2
    vector<vector<int>> ans;
    void helper(vector<int>& nums, vector<int> &subAns, int i=0) {
      if(i==nums.size()){
        ans.push_back(subAns);
        return;
      }
      
      helper(nums, subAns, i+1);
      subAns.push_back(nums[i]);
      helper(nums, subAns, i+1);
      subAns.pop_back();
    }
  
    vector<vector<int>> subsets(vector<int>& nums, int i=0) {
      vector<int> subAns;
      helper(nums, subAns);
      return ans;
    }

};