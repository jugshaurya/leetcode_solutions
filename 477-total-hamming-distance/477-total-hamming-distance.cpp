class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        for(int i = 0; i < 32; i++){
            int zeros = 0;
            int ones = 0;
            for(int j = 0; j < n; j++){
                if((nums[j] & (1 << i)) == 0) zeros++;
                else ones++;
            }
            ans += ones * zeros;
        }
                
        return ans;
    }
};

// O(n^2 logn) TLE
// class Solution {
// public:
//     int totalHammingDistance(vector<int>& nums) {
        
//         int n = nums.size();
//         int ans = 0;
//         for(int i=0;i<n;i++)
//             for(int j=i+1; j<n; j++)
//                 ans += __builtin_popcount(nums[i] ^ nums[j]);
                
//         return ans;
//     }
// };