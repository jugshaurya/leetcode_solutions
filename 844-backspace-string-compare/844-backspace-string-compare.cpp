class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = 0;
        for(auto x: s){
          if(x == '#'){
            if(i!=0) i--;
          }else{
            s[i] = x;
            i++;
          }
        }
        s = s.substr(0,i);  
        i = 0;
        for(auto x: t){
          if(x == '#'){
            if(i!=0) i--;
          }else{
            t[i] = x;
            i++;
          }
        }
        t = t.substr(0,i);
      
        return s==t;
    }
};