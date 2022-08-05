#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void KswapPermutation(int arr[], int n, int k) {
        
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]] = i;
        }
        
        for(int i = 0; i<n; i++){
            if(k == 0) break;
            
            int desired = n - i;
            int desiredPresentAt = mp[desired];
            if(desiredPresentAt == i) continue;
            
            mp[arr[i]] = desiredPresentAt;
            swap(arr[i], arr[desiredPresentAt]);
            mp[arr[i]] = i;
            k--;
            
        }      
    }
};
