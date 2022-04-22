class Solution {
public:
    int trap(vector<int>& height) {
      int n = height.size();
      vector<int> leftMaxValues(n,-1);
      vector<int> rightMaxValues(n,-1);
      
      leftMaxValues[0] = -1;
      int maxx = height[0];
      for(int i=1;i<n;i++){
          if(height[i] < maxx){
            leftMaxValues[i] = maxx;
          }else{
            maxx = height[i];
            leftMaxValues[i] = -1;
          }
      }
      
      rightMaxValues[n-1] = -1;
      maxx = height[n-1];
      for(int i=n-2;i>=0;i--){
          if(height[i] < maxx){
            rightMaxValues[i] = maxx;
          }else{
            maxx = height[i];
            rightMaxValues[i] = -1;
          }
      }
      
      
      int ans = 0;
      for(int i=0;i<n;i++){
        if(leftMaxValues[i]==-1 or rightMaxValues[i]==-1) continue;
        else ans += min(leftMaxValues[i], rightMaxValues[i]) - height[i];
      }
      
      return ans;
    }
};