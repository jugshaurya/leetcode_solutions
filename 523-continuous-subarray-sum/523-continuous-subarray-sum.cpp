// Logic: (pre[j] - pre[i-1]) % k ==0
// since every number is non-negative
// pre[j] >= pre[i-1]
// pre[j] % k == pre[i-1] % k

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        
        // pre[-1] = 0.
        mp[0] = -1;
        
        int sum = 0;
        for(int j=0; j<n; j++){
            sum += nums[j];
            sum %= k;
            if(mp.count(sum) and j - mp[sum] > 1) return true;
            if(mp.count(sum)==0) mp[sum] = j;
        }
        
        return false;
    }
};


