
class Solution {
public:


    // b is bigger string always
    bool differByOneCharAndInSameOrder(string a, string b){

        int i = 0;
        int j = 0;
        int n = a.size();
        int m = b.size();
        int allowed = 1;

        while(i<n and j<m){
          if(a[i]==b[j]){
            i++;
            j++;
          }else{
            if(allowed){
              j++; allowed = 0;
            }else{
              return false;
            }
          }
        }

        return true;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](string A, string B){
            return A.size() < B.size();
        });
        
        map<int, vector<int>> m;
        for(int i = 0; i < n; i++){
            int wl = words[i].size();
            m[wl].push_back(i);
        }
        
        // dp[i] -> length of longest chain ending at ith word.
        vector<int> dp(n, 0);
        for(int i = 0; i < n; i++){
            string word = words[i];
            int wl = word.size();
            if(wl == 1 or m.count(wl-1) == 0) {
                dp[i] = 1;
                continue;
            }

            int ans = 0;
            for(auto idx : m[wl-1]){
                if(differByOneCharAndInSameOrder(words[idx], word)){
                    ans = max(ans, dp[idx]);
                }
            }
            
            dp[i] = ans + 1;
        }
        
        int maxx = 0;
        for(auto x: dp){
            // cout<<x<<" ";
            maxx = max(maxx, x);
        }
        
        return maxx;
        
    }
};
