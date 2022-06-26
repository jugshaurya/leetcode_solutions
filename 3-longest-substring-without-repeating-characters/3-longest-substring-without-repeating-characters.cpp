class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        
        map<char, int> mp;
        int ans = 0;
        while(i<n and j<n){
            if(mp.count(s[j]) == 0){
                mp[s[j]]++;
                j++;
            }else{
                if(mp[s[j]] == 1) {
                    ans = max(ans, j - i);
                    mp[s[i]]--;
                    i++;
                }else{
                    mp[s[j]]++;
                    j++;
                }
            }
        }
        
        ans = max(ans, j - i);
        return ans;
    }
};