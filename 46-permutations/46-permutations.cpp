class Solution {
public:
    
    // Method 1: using `taken` array of indexes
    
    void helper(vector<int>& nums, vector<int> &taken, vector<int> & order, vector<vector<int> >& ans){
        
        if(order.size() == nums.size()){
            // we got a permutation
            vector<int> perm = order;
            ans.push_back(perm);
            return;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(taken[i] == 1) continue;
            taken[i] = 1;
            order.push_back(nums[i]);
            helper(nums, taken, order, ans);
            taken[i] = 0;
            order.pop_back();
        }
            
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> taken(nums.size(), 0);
        vector<vector<int>> ans;
        vector<int> order;
        
        helper(nums, taken, order, ans);
        return ans;
        
    }
    
};