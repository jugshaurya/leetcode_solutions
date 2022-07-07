class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        
        unordered_set<int> mp;
        int ans = 0;
        
        int i = 0;
        int j = 0;

        while(j < n) {
            if(mp.count(s[j]) == 0) {
                mp.insert(s[j]);
                ans = max(ans, j - i + 1);
                j++;
            }else{
                while(s[i] != s[j]){
                    mp.erase(s[i]);
                    i++;
                }
                mp.erase(s[i]);
                i++;
            }   
        }
        
        return ans;
    }
};