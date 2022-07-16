
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) {
 
        int i = 0;
        int j = n-1;
        
        while(i < j){
            if(M[i][j] == 1){
                i++;
            }else if(M[j][i] == 1){
                j--;
            }else{
                i++;
                j--;
            }
        }
        
        if(i==n) return -1;
        
        for(int k =0; k<n; k++){
            if(M[i][k] == 1) return -1;
            if(i!=k and M[k][i] == 0) return -1;
        }
        
        
        return i;
    }
};
