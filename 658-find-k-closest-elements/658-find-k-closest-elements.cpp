class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto it = lower_bound(arr.begin(), arr.end(), x);
        
        vector<int> ans;
        int i, j;
        int n = arr.size();
        
        if(it == arr.end()) {
            // k closest are k elements from back.
            i = n - 2;
            j = n - 1 ;
        }
        
        if(it == arr.begin()) {
            // k closest are k elements from start.
            i = 0;
            j = 1;
        }else{
            if(arr[i] == x) {
                ans.push_back(arr[i]);
                i = it - arr.begin() - 1;
                j = it - arr.begin() + 1;
            }else{
                i = it - arr.begin() - 1;
                j = it - arr.begin();
            }
        }

        while(i>=0 and j < n and ans.size() < k){
            if(abs(x-arr[i]) > abs(x - arr[j])){
                ans.push_back(arr[j]);
                j++;
            }else{
                ans.push_back(arr[i]);
                i--;
            }
        }
        
        while(i>=0 and ans.size() < k){
            ans.push_back(arr[i]);
            i--;
        }
        
        while(j<n and ans.size() < k){
            ans.push_back(arr[j]);
            j++;
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

