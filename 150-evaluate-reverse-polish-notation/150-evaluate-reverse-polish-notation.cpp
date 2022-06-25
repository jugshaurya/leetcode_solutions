
class Solution {
public:
    
    int convertStringToInt(string val){
        int n = val.size();
        int ans = 0;
        bool isNeg = false;
        if(val[0] == '-') isNeg = true;
        else ans = (val[0]-'0');
        for(int i=1;i<n;i++) {
            ans = ans * 10 + (val[i]-'0');
        }
        return isNeg ? -ans: ans;
    }
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            string ch = tokens[i];
            if(ch == "+" or ch == "-" or ch == "*" or ch == "/"){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if(ch == "+") st.push(a + b);
                if(ch == "-") st.push(a - b);
                if(ch == "*") st.push(a * b);
                if(ch == "/") st.push(a / b);
            }else{
                st.push(convertStringToInt(ch));
            }
        }
        
        return st.top();
    }
};