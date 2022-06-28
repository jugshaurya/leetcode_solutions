class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int totalXor = accumulate(nums.begin(), nums.end(), 0, bit_xor<>());
        
        // find 1st set bit ---> @i
        int i = __builtin_ctz(totalXor);
        
        // xor all bits wiht i bit set
        int a = 0;
        for(auto x: nums) a^=(((x>>i)&1) == 1 ? x : 0);
        
        return {a, totalXor^a};
    }
};