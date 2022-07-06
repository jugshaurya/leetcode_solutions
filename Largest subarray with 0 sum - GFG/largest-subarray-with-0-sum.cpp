// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int> &A, int n) {
      map<int, int> mp;
    
      mp[0] = -1;
      int sum = 0;
      int ans = 0;
      for (int j = 0; j<n; j++) {
        sum += A[j];
        if(mp.count(sum)){
          ans = max(ans, j - mp[sum]);     
        }else{
          mp[sum] = j;
        }
      }
    
      return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends