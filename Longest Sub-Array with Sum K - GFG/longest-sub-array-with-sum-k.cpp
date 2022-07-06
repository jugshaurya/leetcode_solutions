// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) {
      map<int, int> mp;

      mp[0] = -1;
      
      int sum = 0;
      int ans = 0;
      for (int j = 0; j < N; j++) {
        sum += A[j];
        if(mp.count(sum - K)){
          ans = max(ans, j - mp[sum - K]);     
        }
        
        if(mp.count(sum) == 0) mp[sum] = j;
      }
    
      return ans;
    }

};

// { Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends