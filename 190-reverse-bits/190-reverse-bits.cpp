class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned int ans = 0;
        for(int i=31; i>=0; i--){
            ans |= ((n>>i)&1)<<(32-i-1);
        }
        
        return ans;
    }
};