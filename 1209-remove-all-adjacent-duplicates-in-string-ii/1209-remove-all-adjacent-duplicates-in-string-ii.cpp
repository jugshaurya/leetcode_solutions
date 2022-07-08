class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(auto x: s){
            if(st.empty() or st.top().first != x) {
                st.push({x, 1});
                continue;
            }
            
            if(st.top().second != k-1){
                st.push({x, st.top().second + 1});
                continue;
            }
            
            int tmp = k-1;
            while(tmp--) st.pop();
        }
        
        string ans;
        while(!st.empty()){
            ans += st.top().first;
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};