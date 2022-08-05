// using two sets
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1,s2;
        
        for(auto x: nums1) s1.insert(x);
        for(auto x: nums2) s2.insert(x);
        
        vector<int> ans;
        for(auto x: s1){
            if(s2.count(x)) ans.push_back(x);
        }
        
        return ans;
    }
};