class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 0) return false;
        if(n == INT_MIN) return false;
        
        // should be a power of 2 as well
        // and set bit should be @odd place
        
        // return (n&(n-1)) == 0 and (n&(0xAAAAAAAA)) == 0;
        // or
        return (n&(n-1)) == 0 and (n&(0x55555555)) != 0;
    }
};