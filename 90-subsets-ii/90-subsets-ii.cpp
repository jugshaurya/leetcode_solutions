// // Common: without storing all generated substes in a set. 

// // Method 1: using map at each rec call O(2^n)
// class Solution {
// public:
//     vector<vector<int>> ans;
//     void helper(vector<int> &subans, map<int, int> &mp){
//         if(mp.empty()) {
//             ans.push_back(subans);
//             return;
//         }
        
//         auto [key, val] = *mp.begin();
        
//         // frequency is one
//         if(val == 1) {
//             mp.erase(key);
//             helper(subans, mp);
            
//             subans.push_back(key);
//             helper(subans, mp);
//             subans.pop_back();
            
//             mp[key] = val; 
//         }else {
//             mp[key] -= 1;
//             subans.push_back(key);
//             helper(subans, mp);
//             subans.pop_back();
            
//             mp.erase(key);
//             helper(subans, mp);
//             mp[key] = val;
//         }
        
//         return;
//     }
    
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
                
//         map<int, int> mp;
//         for(auto x: nums) mp[x]++;
        
//         vector<int> subans;
//         helper(subans, mp);
        
//         return ans;
//     }
// };


// Method 2: using i variable on sorted array O(n * 2^n)
class Solution {
public:
    vector<vector<int>> ans;
    void helper(int i, vector<int> &nums, vector<int> &subans){
        int n = nums.size();
        if(i == n) {
            ans.push_back(subans);
            return;
        }
        
        // taking ith value
        subans.push_back(nums[i]);
        helper(i+1, nums,subans);
        subans.pop_back();
        
        // leaving all a[i] values present continuously as we sorted nums already
        while(i + 1 < n and nums[i+1] == nums[i]) i++;
        helper(i + 1, nums, subans);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subans;
        helper(0, nums, subans);
        return ans;
    }
};
