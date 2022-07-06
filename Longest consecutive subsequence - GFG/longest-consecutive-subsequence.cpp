// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N){
        unordered_set<int> s;
        vector<int> nums(arr, arr + N);
        for(auto x: nums) s.insert(x);
        
        int longestSeq = 0;
        for(auto x: nums) {
            if(s.count(x - 1)) continue;
            int tmp = x + 1;
            while(s.count(tmp) == 1) tmp++;
            longestSeq = max(longestSeq, tmp - x);
        }
        
        return longestSeq;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends