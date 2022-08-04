class Solution {
public:
    // does a contains b ?
    bool contains(unordered_map<char, int>& a, unordered_map<char, int>& b){
        for(auto x: b){
            if(a.count(x.first) == 0) return false;
            if(a[x.first] < x.second) return false;
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        unordered_map<char, int> tMap;
        for(auto x: t) tMap[x]++;
        
        int i = 0;
        int j = 0;
        unordered_map<char, int> mp;
        mp[s[0]]++;
        
        int n = s.size();
        string minString;
        int minLength = n + 1;
        while(i < n) {
            if(contains(mp, tMap)) {
                if(j - i + 1 < minLength){
                    minLength = j - i + 1;
                    minString = s.substr(i, j-i+1);
                }
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            } else {
                if(j == n) break;;
                j++; 
                mp[s[j]]++;  
            } 
        }
        
        return minString;
    }
};