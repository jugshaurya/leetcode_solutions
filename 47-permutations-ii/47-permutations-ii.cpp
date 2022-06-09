class Solution {
public:
// ======= Method 1: using `taken` array of indexes and `set` data structure ============
//     void helper(vector<int>& nums, vector<int> &taken, vector<int> & order, set<vector<int> >& ans){
//         if(order.size() == nums.size()){
//             ans.insert(order);
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
//         set<vector<int>> ans;
//         vector<int> order;
        
//         helper(nums, taken, order, ans);
        
//         vector<vector<int> > res;
//         for(auto x: ans){
//             res.push_back(x);
//         }
//         return res;
//     }
    
// ====== Method 2: using swapping and `set` Data strucutre  ====================
//     void helper(vector<int>& nums, int start, int end, set<vector<int> >& ans){
//         if(start == end){
//             ans.insert(nums);
//             return ;
//         }
//         for(int i = start; i<=end; i++){
//             swap(nums[start], nums[i]);
//             helper(nums, start + 1, end, ans);
//             swap(nums[start], nums[i]);
//         }
//     }
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         set<vector<int>> ans;
//         helper(nums, 0, nums.size()-1 ,ans);

//         vector<vector<int> > res;
//         for(auto x: ans){
//             res.push_back(x);
//         }
//         return res;
//     }
    
// ============= Method 3: using swapping and without set but using `hashmap` =======
    
    void helper(map<int,int> &mp, vector<int>& ans, vector<vector<int>> &res) {
        if(mp.size() == 0){
            res.push_back(ans);
            return; 
        }
        
        map<int, int> tmp = mp;
        for(auto x: tmp) {
            int f = x.first;
            mp[f]--;

            if(mp[f] == 0) mp.erase(f);
 
            ans.push_back(f);
            helper(mp, ans, res);
            ans.pop_back();
            mp[f]++;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int, int> mp;
        for(auto x: nums) mp[x]++;
        vector<int> ans;
        vector<vector<int> > res;
        
        helper(mp, ans, res);
        return res;
    }
};
