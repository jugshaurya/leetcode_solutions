class Solution {
public:
    bool backspaceCompare(string s, string t) {
      int n = s.size();
      int m = t.size();
      int i = n-1;
      int j = m-1;
      while(true){
        // if((i<0 and j>=0) or (j<0 and i>=0)) return false;
        if(i<0 and j<0) break;
        if(i>=0 and j>=0 and s[i] == t[j] and s[i]!='#' and t[j]!='#') {
          i--;
          j--;
          continue;
        }
        
        if(i>=0 and j>=0 and s[i] != t[j] and s[i]!='#' and t[j]!='#') {
          return false;
        }
        
        if(i>=0 and s[i] == '#'){
          int cnt = 0;
          while(i>=0 and s[i] == '#'){
            cnt++;
            i--;
          }
          while(cnt--){
            if(i>=0 and s[i]=='#') cnt+=2;
            i--;
          }
          cout<<i<<"s ";
        }
        
        if(j>=0 and t[j] == '#'){
          int cnt = 0;
          while(j>=0 and t[j] == '#'){
            cnt++;
            j--;
          }
          while(cnt--){
            if(j>=0 and t[j]=='#') cnt+=2;
            j--;
          }
          cout<<j<<"f ";
        }
        
        if(i>=0 and j<0 and s[i]!='#') return false;
        if(i<0 and j>=0 and t[j]!='#') return false;
      }
      
      return true;
    }
};