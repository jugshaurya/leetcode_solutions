class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> ans;
        for(int i = 0; i < n + m; i++) {
            int biggerDim = max(m, n);
            if((i & 1) == 0){
                for(int j = 0; j < biggerDim; j++){
                    int row = i - j;
                    int col = j;
                    if(row >= 0 and col >= 0 and row < m and col < n){
                        ans.push_back(mat[row][col]);
                    }
                }
            }else{
                for(int j = 0; j < biggerDim; j++){
                    int row = j;
                    int col = i - j;
                    if(row >= 0 and col >= 0 and row < m and col < n){
                        ans.push_back(mat[row][col]);
                    }
                }
            }
        }
        
        return ans;
    }
};


//     m n
//     0 5
//     1 4
//     2 3
//     3 2
//     4 1
//     5 0
    
