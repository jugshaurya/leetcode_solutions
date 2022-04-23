class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for(auto x: s){
          if(x>='0' and x<='9') t+=x;
          if(tolower(x) >= 'a' and tolower(x)<='z') t+=tolower(x);
        }
        string u = t;
        reverse(t.begin(), t.end());
        return t==u;
    }
};