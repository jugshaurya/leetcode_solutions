class Solution {
public:
    
    vector<int> getNextGreaterElement(vector<int>& num){
        int n = num.size();
        stack<int> s;
        
        vector<int> ans;
        // Tip: Traverse from right
        for(int i=n-1;i>=0;i--){
            while(!s.empty() and num[s.top()] <= num[i]){
                s.pop();
            }
            if(s.empty()) {
                s.push(i);
                ans.push_back(0);
            }else{
                ans.push_back(s.top() - i);
                s.push(i);
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans = getNextGreaterElement(temperatures);
        int n = temperatures.size();
        return ans;
    }
};