vector<int> dp;
class Solution {
  public:
  int minRoundsNeeded(int n) {
    if (n < 2) return 1e9;
    if (n == 2) return 1;
    if (n == 3) return 1;
    if (dp[n] != -1) return dp[n];
    return dp[n] = 1 + min(minRoundsNeeded(n - 2), minRoundsNeeded(n - 3));
  }

  int minimumRounds(vector<int>& tasks) {
    // Method 1: using sorting + DP (nlogn + n) 
    // int n = tasks.size();

    // sort(tasks.begin(), tasks.end());
    // dp = vector<int>(n + 1, -1);

    // int ans = 0;
    // int cnt = 1;
    // for (int i = 1; i < n; i++) {
    //   if (tasks[i] == tasks[i - 1]) cnt++;
    //   else {
    //     if (cnt == 1) return -1;
    //     ans += minRoundsNeeded(cnt);
    //     cnt = 1;
    //   }
    // }

    // if (cnt == 1) return -1;
    // ans += minRoundsNeeded(cnt);
    // return ans;

    // Method 2: using Hashing + DP =  O(n)
    
    int n = tasks.size();
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) m[tasks[i]]++;

    dp = vector<int>(n + 1, -1);
    int ans = 0;
    for (auto [task, freq] : m) {
      if (freq == 1) return -1;
      ans += minRoundsNeeded(freq);
    }
    return ans;
  }
};
