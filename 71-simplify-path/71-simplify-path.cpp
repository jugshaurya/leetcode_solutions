class Solution {
public:
    string simplifyPath(string path) {

        vector <string> tokens;
        stringstream check1(path);
        string temp;
        while(getline(check1, temp, '/')){
            if(temp.size()==0) continue;
            tokens.push_back(temp);
        }
        
        stack<string> st;
        for(auto x: tokens){
            if(x == ".." and st.empty()) continue;
            if(x == ".." and !st.empty()) {st.pop(); continue;}
            if(x == ".") continue;
            st.push(x);
        }
        
        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            ans = "/" + ans;
            st.pop();
        }
        
        if(ans == "") return "/";
        return ans;
    }
};