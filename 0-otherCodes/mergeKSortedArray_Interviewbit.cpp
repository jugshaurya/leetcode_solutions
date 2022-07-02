/*
Merge K sorted arrays!

Medium

105

11
Asked In:
Trakinvest
Problem Description

You are given K sorted integer arrays in a form of 2D integer matrix A of size K X N.

You need to merge them into a single array and return it.



Problem Constraints
1 <= K, N <= 103

0 <= A[i][j] <= 108

A[i][j] <= A[i][j+1]



Input Format
First and only argument is an 2D integer matrix A.



Output Format
Return a integer array denoting the merged array you get after merging all the arrays in A.
*/

struct Trip {
    int val;
    int i; 
    int j;
};

class Cmp{
    public:
    bool operator()(Trip a, Trip b){
        return a.val > b.val;
    }
};

vector<int> Solution::solve(vector<vector<int> > &A) {
    
    int m = A.size();
    int n = A[0].size();
    
    priority_queue<Trip, vector<Trip> , Cmp> pqmin;
    vector<int> ans;
    for(int i=0; i<m; i++) pqmin.push({A[i][0], i, 0});
    
    while(!pqmin.empty()){
        auto front = pqmin.top();
        pqmin.pop();
        ans.push_back(front.val);
        if(front.j + 1 < n){
            pqmin.push({A[front.i][front.j+ 1 ], front.i, front.j+1});
        }
    }
    return ans;
}
