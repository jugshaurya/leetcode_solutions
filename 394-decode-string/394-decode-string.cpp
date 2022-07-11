class Solution {
public:
    string decodeString(string s) {
        stack <char> st;
        for(auto ch: s){
            if(ch != ']'){
                st.push(ch);
                continue;
            }
            
            string tmp;
            while(st.top()!='['){
                tmp += st.top();
                st.pop();
            }
            
            reverse(tmp.begin(), tmp.end());
            
            // popping '['
            st.pop();
            int num = 0;
            int digits = 0;
            while(!st.empty() and st.top()>='0' and st.top() <= '9'){
                num = num + (st.top() - '0')* pow(10, digits);
                digits++;
                st.pop();
            }
            cout<<num;
            
            string ans;
            while(num--){
                ans += tmp;
            } 
            
            for(auto x: ans){
                st.push(x);
            }
        }
        
        string res;
        while(!st.empty()){
            res += st.top(); st.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};