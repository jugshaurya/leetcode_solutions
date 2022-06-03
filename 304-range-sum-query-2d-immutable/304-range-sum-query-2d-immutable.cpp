class NumMatrix {
public:
    
    vector<vector<int> > matrix;
    vector<vector<int> > preSum;
    int m,n;
    
    NumMatrix(vector<vector<int>>& matrix) {
        this->m = matrix.size();
        this->n = matrix[0].size();
        this->matrix = matrix;
        this->preSum = matrix;
        
        // filling the prefix sum matrix
        preSum[0][0] = matrix[0][0];

        for(int it = 1 ;it < m; it++){
            preSum[it][0] += preSum[it-1][0];
        }
        
        for(int it = 1 ;it < n; it++){
            preSum[0][it] += preSum[0][it-1];
        }
        
        for(int i = 1 ;i < m; i++){
            for(int j = 1 ;j < n; j++){
                preSum[i][j] += preSum[i][j-1] + preSum[i-1][j] - preSum[i-1][j-1];
            }
        }
        
        //  print
        for(int i = 0 ;i < m; i++){
            for(int j = 0 ;j < n; j++){
                cout<<preSum[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int ans = preSum[row2][col2];
        if(col1-1>=0) ans -= preSum[row2][col1-1];
        if(row1-1>=0) ans -= preSum[row1-1][col2];
        if(col1-1>=0 and row1-1>=0) ans += preSum[row1-1][col1-1];
        
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */