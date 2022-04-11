class Solution {
public:
    vector<string> arr;
    int helper(int i, string ans){

        if(i==arr.size()) {
            if(ans.size() > 26) return INT_MIN;
            sort(ans.begin(), ans.end());
            for(int i = 1; i< ans.size(); i++){
                if(ans[i]==ans[i-1]) return INT_MIN;
            }
            return ans.size();
        }
            
        int opt1 = helper(i+1, ans);
        int opt2 = INT_MIN;
        ans += arr[i]; 
        if(ans.size() <= 26) opt2 = helper(i+1, ans);
        return max(opt1, opt2);
    }
    
    int maxLength(vector<string>& temp) {
        arr = temp;
        return helper(0, "");
    }
};