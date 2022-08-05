class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> mp;
        for(auto x: nums1) mp[x]++;
        
        vector<int> ans;
        for(auto x: nums2) {
            if(mp.count(x) == 0) continue;
            if(mp[x] == 0) continue;
            ans.push_back(x);
            mp[x]--;
        }
        
        return ans;
    }
};

        
