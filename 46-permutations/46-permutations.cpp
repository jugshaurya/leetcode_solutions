class Solution {
public:
    
    // Method 1: using `taken` array of indexes
    
    void helper(vector<int>& nums, vector<int> &taken, vector<int> & order, vector<vector<int> >& ans){
        if(order.size() == nums.size()){
            // we got a permutation
            // vector<int> perm = order;
            ans.push_back(order);
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

//     // Method 2: using swapping
//     void helper(vector<int>& nums, int start, int end, vector<vector<int> >& ans){
        
//         if(start == end){
//             // we got a permutation
//             // vector<int> per = nums;
//             ans.push_back(nums);
//             return ;
//         }
        
//         for(int i = start; i<=end; i++){
//             swap(nums[start], nums[i]);
//             helper(nums, start + 1, end, ans);
//             swap(nums[start], nums[i]);
//         }
        
//     }
    
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> ans;
//         helper(nums, 0, nums.size()-1 ,ans);
//         return ans;
        
//     }

};


















