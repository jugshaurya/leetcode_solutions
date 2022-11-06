class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        for(auto ch: s) mp[ch]++;
        
        int ans = 0;
        bool hasOdd = false;
        for(auto &[_,s]: mp){
            if(s&1) {
                ans += s - 1;
                hasOdd = true;
            }
            else ans += s;
        }
      
        return ans + hasOdd;
    }
};