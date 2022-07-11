class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        
        stack<int> st;
        st.push(asteroids[0]);
        
        for(int i = 1; i < n; i++){
            int x = asteroids[i];
            if(st.empty() or x > 0 or st.top() < 0){
                st.push(x);
                continue;
            }
            
            // => stack top is +ve value and my x is -ve
            
            while(!st.empty() and st.top() > 0 and st.top() < -x) st.pop();

            if(st.empty() or st.top() < 0){
                st.push(x);
                continue;
            }
            
            if(st.top() == -x){
                // both will break
                st.pop();
                continue;
            }
            
            if(st.top() > -x){
                continue;                
            }
        }
                
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};