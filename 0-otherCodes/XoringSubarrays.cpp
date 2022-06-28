/*
Given an integer array A of size N.

You need to find the value obtained by XOR-ing the contiguous subarrays, followed by XOR-ing the values thus obtained. Determine and return this value.

For example, if A = [3, 4, 5] :

Subarray    Operation   Result
3       None            3
4       None            4
5       None            5
3,4   3 XOR 4         7
4,5   4 XOR 5         1
3,4,5    3 XOR 4 XOR 5   2

Now we take the resultant values and XOR them together:

3 ⊕ 4 ⊕ 5 ⊕ 7 ⊕ 1⊕ 2 = 6 we will return 6.

*/

int Solution::solve(vector<int> &A) {
    int n = A.size();
    int ans = 0;
    
    for(int i = 1; i <= n; i++){
        int freq = i * (n - i + 1); 
        if(freq % 2 == 1){
            ans ^= A[i-1];
        }
    }
    
    return ans;
}
