class Solution {
  public:
  int dp[201][20005];
  vector<int> arr;

  bool rec(int i, int sum) {
    int n = arr.size();
      
    if (i == n and sum == 0) return true;
    if (i == n and sum != 0) return false;

    if (dp[i][sum] != -1) return dp[i][sum];

    int ans = rec(i + 1, sum);
    if(sum - arr[i] >= 0) ans = ans or rec(i + 1, sum - arr[i]);
    return dp[i][sum] = ans;
  }

  bool canPartition(vector<int> &nums) {
    this->arr = nums;

    int total = accumulate(nums.begin(), nums.end(), 0);
    if (total & 1) return false;
      
    memset(dp, -1, sizeof(dp));
    return rec(0, total / 2);
  }

};
