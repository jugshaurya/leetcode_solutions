class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // get a matrix of dimension(n,m) using given matrix of (m,n)     
        
        vector<vector<int> > mat(n, vector<int>(m));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                mat[i][j] = matrix[j][i];
        
        return mat;
    }
};