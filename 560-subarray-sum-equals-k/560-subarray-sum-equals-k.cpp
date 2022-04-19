class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        map<int, int> mp;
      
//         for(int i=0;i<n;i++){
//           if(i) prefixSum[i] = prefixSum[i-1] + nums[i];
//           else prefixSum[i] = nums[i];
//         }
        
//         int ans = 0;
//         mp[0]++;
//         for(auto x: prefixSum){
//           if(mp.count(x-k)) ans+= mp[x-k];
//           mp[x]++;
//         }
        
        int ans = 0;
        mp[0]++;
        for(int i=0;i<n;i++){
          if(i) prefixSum[i] = prefixSum[i-1] + nums[i];
          else prefixSum[i] = nums[i];
          
          if(mp.count(prefixSum[i]-k)) ans+= mp[prefixSum[i]-k];
          mp[prefixSum[i]]++;
        }
        
        return ans;
    }
};