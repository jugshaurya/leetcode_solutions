// O(1) space
// O(32n) time
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            int bit = 0;
            for(auto x: nums){
                bit += ((x >> i) & 1); 
                bit %= 3;
            }
            ans |= (bit << i);
        }
        
        return ans;
    }
};

// // O(32) space
// // O(32n) time
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         vector<int> bitsArray(32, 0);
        
//         for(auto x: nums){
//             for(int i = 0; i < 32; i++) {
//                 bitsArray[i] += ((x >> i) & 1); 
//                 bitsArray[i] %= 3; 
//             }
//         }
        
//         int ans = 0;
//         for(int i = 0; i < 32; i++){
//             ans |= bitsArray[i] << i; 
//         }
        
//         return ans;
//     }
// };