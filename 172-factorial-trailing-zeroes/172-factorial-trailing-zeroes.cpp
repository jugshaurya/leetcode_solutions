class Solution {
public:
    int trailingZeroes(int n) {
      
      int ans = 0;
      int p = 5;
      while(n){
        ans += n/p; // floor(n/p)
        n = n/p;
      }
      
      return ans;
    }
};