/*
You are given an array of N integers, A1, A2 ,..., AN and an integer B. Return the of count of distinct numbers in all windows of size B.
Formally, return an array of size N-B+1 where i'th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,..., Ai+B-1.
NOTE:  if B > N, return an empty array.

Input Format
First argument is an integer array A
Second argument is an integer B.

Output Format
Return an integer array.
Example Input
Input 1:
 A = [1, 2, 1, 3, 4, 3]
 B = 3
Input 2:
 A = [1, 1, 2, 2]
 B = 1
Example Output
Output 1:
 [2, 3, 3, 2]
Output 2:
 [1, 1, 1, 1]

*/
vector<int> Solution::dNums(vector<int> &nums, int k) {
    map<int,int> mp;
    for(int i=0; i<k; i++) mp[nums[i]]++;
    
    vector<int> ans;
    ans.push_back(mp.size());
    
    int n = nums.size();
    int j = k;
    while(j<n) {
        mp[nums[j]]++;
        int last = j-k;
        mp[nums[last]]--;
        if(mp[nums[last]] == 0) mp.erase(nums[last]);
        j++;
        ans.push_back(mp.size());
    }
    return ans;
}
