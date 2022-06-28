class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bitsArray(32, 0);
        
        for(auto x: nums){
            for(int i = 0; i < 32; i++) {
                bitsArray[i] += ((x >> i) & 1); 
                bitsArray[i] %= 3; 
            }
        }
        
        int ans = 0;
        for(int i = 0; i < 32; i++){
            ans |= bitsArray[i] << i; 
        }
        
        return ans;
    }
};