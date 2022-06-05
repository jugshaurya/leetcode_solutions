class Solution {
public:
    
    int memo[201][20005];
    bool helper(vector<int> &A, int i, int sum, int B){
        int n = A.size();
        if(i==n and sum == B) return true; 
        if(i==n) return false; 
        if(memo[i][sum] != -1) return memo[i][sum];
        return memo[i][sum] = helper(A, i+1, sum + A[i], B) or helper(A, i+1, sum, B);
    }

    // DP Form: dp(i,sum)
    bool subsetSum(vector<int> &A, int B) {
        memset(memo, -1, sizeof(memo));
        return helper(A,0 ,0,B);
    }


    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        
        if(total&1) return false;
        return subsetSum(nums, total/2);
    }
};


