class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mp;
        int isMappedAlready[256] = {0};

        int n = s.size();
        for(int i=0; i<n; i++){
            if(mp.count(s[i]) == 0){
                if(isMappedAlready[t[i]]) return false;
                mp[s[i]] = t[i];
                isMappedAlready[t[i]] = 1;
            }else {
                cout<<i<<endl;
                if(t[i] != mp[s[i]]) return false;
            }
        }

        return true;

    }
};