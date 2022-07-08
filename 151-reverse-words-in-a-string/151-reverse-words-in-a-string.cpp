#include<string>
class Solution {
public:
    string reverseWords(string s) {
        
        string token;
        istringstream is(s);
        
        string ans;
        while(getline(is, token, ' ')){
            if(token.size()!= 0){
                reverse(token.begin(), token.end());
                ans += token;
                ans += " ";
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans.substr(1);
    }
};