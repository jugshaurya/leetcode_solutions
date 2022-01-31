class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> alphabets(26,0);
        for(auto ch: s){
            alphabets[ch-'a']+=1;
        }
        for(auto ch: t){
            alphabets[ch-'a']-=1;
        }
        for(auto x: alphabets){
            if(x!=0) return false;
        }
        return true;
     }
};