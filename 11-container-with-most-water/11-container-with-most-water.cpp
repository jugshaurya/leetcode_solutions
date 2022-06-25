class Solution {
public:
    
    // using maths 
    // we want to maximize the expression
    // exp = (j-i)*(min(height[i], height[j]));
    // (j-i), will always be decreasing.as we move from i and j toward each other.
    // but we can maximize `min(height[i], height[j])` if we take keep on discarding the smaller among two.
    // Why? because, smaller one among both is the one that is reducing the expression value.
    
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n-1;
        
        int ans = 0;
        
        // dont take `=` because, we dont want area formed by single building. 
        while(i <= j) {
            ans = max(ans, (j-i)*(min(height[j], height[i])));
            if(height[i] < height[j])  i++;
            else j--;
        }
        
        
        return ans;
    }
};