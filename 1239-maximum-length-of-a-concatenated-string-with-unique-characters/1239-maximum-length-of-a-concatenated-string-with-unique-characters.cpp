class Solution {
public:
    
    // Method 1: simple recursion O(2^n * 26)    
    // vector<string> arr;
    //     int helper(int i, string ans){
    //         if(i==arr.size()) {
    //             if(ans.size() > 26) return INT_MIN;
    //             sort(ans.begin(), ans.end());
    //             for(int i = 1; i< ans.size(); i++){
    //                 if(ans[i]==ans[i-1]) return INT_MIN;
    //             }
    //             return ans.size();
    //         }

    //         int opt1 = helper(i+1, ans);
    //         int opt2 = INT_MIN;
    //         ans += arr[i]; 
    //         if(ans.size() <= 26) opt2 = helper(i+1, ans);
    //         return max(opt1, opt2);
    //     }

    //     int maxLength(vector<string>& temp) {
    //         arr = temp;
    //         return helper(0, "");
    //     }
    
    //  Method 2: Dp + Bitmasking O(2^n * 26)
    
    vector<string> arr;
    
    int helper(int i, int mask){
        int n = arr.size();
        if(i == n) {
            int j = n - 1;
            string temp;
            while (mask) {
                if(mask&1)  temp += arr[j];
                if(temp.size() > 26) return INT_MIN;
                mask >>= 1;
                j--;
            }
 
            sort(temp.begin(), temp.end());
            for(int i = 1; i < temp.size(); i++){
                if(temp[i] == temp[i-1]) return INT_MIN;
            }
            
            return temp.size();
        }
        
        return max(helper(i+1, mask), helper(i+1, (mask| (1<<i))));
    }
    
    int maxLength(vector<string>& temp) {
        arr = temp;
        return helper(0, 0);
    }
    
};