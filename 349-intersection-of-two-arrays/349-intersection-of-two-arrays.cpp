// using one sets
// Time: O(n + m)
// Space: O(n)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        for(auto x: nums1) s1.insert(x);
        
        vector<int> ans;
        for(auto x: nums2) {
            if(s1.count(x)) {
                ans.push_back(x);
                s1.erase(x);
            }
        }
        
        return ans;
    }
};

// using two sets
// Time: O(n + m)
// Space: O(n + m)
// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         unordered_set<int> s1,s2;
        
//         for(auto x: nums1) s1.insert(x);
//         for(auto x: nums2) s2.insert(x);
        
//         vector<int> ans;
//         for(auto x: s1){
//             if(s2.count(x)) ans.push_back(x);
//         }
        
//         return ans;
//     }
// };