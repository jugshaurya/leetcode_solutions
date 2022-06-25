class Solution {
public:
    // O(n)
    int largestRectangleArea(vector<int> heights) {
        // formula = ans = max(ans, (nextsmaller[i] - prevSmaller[i] -1) * heights[i])
        int n = heights.size();
        vector<int> ans = heights;
        
        // negeate heights 
        // O(n)
        for(int i=0; i < n; i++){
            ans[i] = -ans[i];
        }
        
        // Add getNextSmaller(heights)*heights[i] to ans   
        // O(n)
        stack<int> s;
        for(int i=n-1; i>=0; i--){
            while(!s.empty() and heights[s.top()] >= heights[i]) s.pop();
            if(s.empty()) ans[i] += n * heights[i];
            else ans[i] += s.top() * heights[i];
            s.push(i);
        }
        
        // clear the stack
        // O(n)
        while(!s.empty()) s.pop();
        
        // Subtract getPrevSmaller(heights)*heights[i] from ans   
        // O(n)
        for(int i=0; i < n; i++){
            while(!s.empty() and heights[s.top()] >= heights[i]) s.pop();
            if(s.empty()) ans[i] -= (-1)*heights[i];
            else ans[i] -= s.top() * heights[i];
            s.push(i);
        }
        
        // O(n)
        int maxx = 0;
        for(int i = 0; i < n; i++){
            maxx = max(maxx, ans[i]);
        }
        return maxx;
    }
    // O(n*n)
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int ans = 0;
        vector<vector<int>> mat(m, vector<int>(n, 0));
        // O(n)
        for(int j=0; j<n;j++){
            mat[0][j] = matrix[0][j] == '0' ? 0 : 1;
        }
        // O(n)
        ans = max(ans, largestRectangleArea(mat[0]));
        
        // O(n*n)
        for(int i=1;i<m;i++){
            // O(n)
            for(int j =0;j<n;j++){
                if(matrix[i][j] == '1') mat[i][j] = 1 + mat[i-1][j]; 
            }
            // O(n)
            ans = max(ans, largestRectangleArea(mat[i]));
        }
        
        return ans;
    }
};