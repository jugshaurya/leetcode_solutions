class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> mp(101, 0);
        for(auto x: nums) mp[x]++;
        
        int sum = 0;
        for(int i=0; i<101; i++) {
            int old = mp[i];
            mp[i] = sum;
            sum += old;
        }
        
        vector<int> ans;
        for(auto x: nums) ans.push_back(mp[x]);
        return ans;
    }
};