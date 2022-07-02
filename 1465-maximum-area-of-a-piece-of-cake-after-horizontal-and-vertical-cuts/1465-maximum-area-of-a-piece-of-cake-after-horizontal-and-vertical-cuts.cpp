const int M  = 1e9 + 7; 

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        int m = horizontalCuts.size();
        int maxWidth = max(horizontalCuts[0], h - horizontalCuts[m-1]); 
        for(int i=1; i<m;i++){
            maxWidth = max(maxWidth, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        
        int n = verticalCuts.size();
        int maxHeight = max(verticalCuts[0], w - verticalCuts[n-1]); 
        for(int i=1; i<n;i++){
            maxHeight = max(maxHeight, verticalCuts[i] - verticalCuts[i-1]);
        }
        
        return ((long long)maxWidth* maxHeight) % M;
    }
};