class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        // get a matrix of dimension(n,m) using given matrix of (m,n)     
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int> > mat(n, vector<int>(m,0));
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                mat[i][j] = matrix[j][i];
        
        return mat;
    }
};