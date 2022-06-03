class Solution {
public:
    
    // =============== Method 1: using `taken` array of indexes ========================
    
//     void helper(vector<int>& nums, vector<int> &taken, vector<int> & order, vector<vector<int> >& ans){

//         if(order.size() == nums.size()){
//             ans.push_back(order);
//             return;
//         }
        
//         for(int i=0; i<nums.size(); i++){
//             if(taken[i] == 1) continue;
//             taken[i] = 1;
//             order.push_back(nums[i]);
//             helper(nums, taken, order, ans);
//             taken[i] = 0;
//             order.pop_back();
//         }
            
//     }
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         vector<int> taken(nums.size(), 0);
//         vector<vector<int>> ans;
//         vector<int> order;
        
//         helper(nums, taken, order, ans);
//         return ans;
        
//     }

    // ===================== Method 2: using swapping ========================
    
    void helper(vector<int>& nums, int start, int end, set<vector<int> >& ans){

        if(start == end){
            ans.insert(nums);
            return ;
        }
        
        for(int i = start; i<=end; i++){
            swap(nums[start], nums[i]);
            helper(nums, start + 1, end, ans);
            swap(nums[start], nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        helper(nums, 0, nums.size()-1 ,ans);
        
        vector<vector<int> > res;
        for(auto x: ans){
            res.push_back(x);
        }
        return res;
        
    }

};
