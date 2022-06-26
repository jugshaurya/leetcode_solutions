class Solution {
public:
    int firstUniqChar(string s) {
        map<int, int> m;
        for(auto x: s) m[x]++;
        for(int i=0; s[i] != '\0'; i++) 
            if(m[s[i]] == 1) 
                return i;
        return -1;
    }
};