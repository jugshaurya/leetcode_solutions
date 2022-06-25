class Solution {
public:
    string simplifyPath(string path) {

        vector <string> tokens;
        stringstream check1(path);
        string temp;
        while(getline(check1, temp, '/')){
            if(temp.size() == 0) continue;
            tokens.push_back(temp);
        }
        
        stack<string> st;
        for(auto x: tokens){
            if(x == ".." and st.empty()) continue;
            if(x == ".." and !st.empty()) {st.pop(); continue;}
            if(x == ".") continue;
            st.push(x);
        }
        
        list<string> l;
        while(!st.empty()) {
            l.push_front(st.top());
            l.push_front("/");
            st.pop();
        }
        
        string ans = "";
        while(!l.empty()){
            ans += l.front();
            l.pop_front();
        }
        
        if(ans == "") return "/";
        return ans;
    }
};