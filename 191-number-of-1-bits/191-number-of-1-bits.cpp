class Solution {
public:
    
    // O(logn)
    // int hammingWeight(uint32_t n) {
    //     int cnt = 0;
    //     while(n){
    //         cnt++;
    //         n = n & (n-1);
    //     }
    //     return cnt;
    // }
    
    
    // O(logn)
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }

};