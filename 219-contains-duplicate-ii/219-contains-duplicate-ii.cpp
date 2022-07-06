class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> mp;
        int n = nums.size();
        
        for(int j = 0; j<n; j++){
            if(mp.count(nums[j]) and j - mp[nums[j]] <= k) return true;
            mp[nums[j]] = j;
        }
        
        return false;
    }
};