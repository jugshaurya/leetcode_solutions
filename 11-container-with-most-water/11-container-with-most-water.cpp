class Solution {
public:
    int maxArea(vector<int>& height) {
      int n = height.size();
      int s = 0;
      int e = n-1;
      int ans = 0;
      while(s < e){
        ans = max(ans, (e-s)*min(height[s], height[e]));
        if(height[s]< height[e]) s++;
        else e--;
      }
      return ans;
    }
};