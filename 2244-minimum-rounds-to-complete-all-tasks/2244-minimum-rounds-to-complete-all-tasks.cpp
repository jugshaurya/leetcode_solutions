// Method 2: Greedy Works here
class Solution {
  public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();

        unordered_map<int, int> mp;
        for (auto x: tasks) mp[x]++;

        int ans = 0;
        for (auto [_, freq] : mp) {
            if (freq == 1) return -1;
            ans += (freq / 3);
            if(freq % 3 != 0) ans += 1;
        }

        return ans;
    }
};

// // Method 1: hashmap + DP 
// class Solution {
//   public:
//     int dp[100005];
//     int rec(int n) {
//         if(n < 2) return 1e9; 
//         if(n == 2 or n == 3) return 1;
        
//         if (dp[n] != -1) return dp[n];
        
//         return dp[n] = 1 + min(rec(n - 2), rec(n - 3));
//     }


//     int minimumRounds(vector<int>& tasks) {
//         int n = tasks.size();

//         unordered_map<int, int> mp;
//         for (auto x: tasks) mp[x]++;

//         memset(dp, -1, sizeof(dp));

//         int ans = 0;
//         for (auto [task, freq] : mp) {
//             if (freq == 1) return -1;
//             else ans += rec(freq);
//         }

//         return ans;
//     }
// };
