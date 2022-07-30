class Solution {
public:
    int memo[505][505];
    // dp(i, j)
    int recurse(int i, int j, string& word1, string& word2) {
        int n = word1.size();
        int m = word2.size();
        
        if(i == n) return m - j;
        if(j == m) return n - i;
        
        if(memo[i][j] != -1) return memo[i][j];
        
        if(word1[i] == word2[j]) return memo[i][j] = recurse(i+1, j+1, word1, word2);
        return memo[i][j] = 1 + min({
            recurse(i, j+1, word1, word2),
            recurse(i+1, j, word1, word2),
            recurse(i+1, j+1, word1, word2)
        });
    }
    
    int minDistance(string word1, string word2) {
        memset(memo, -1, sizeof(memo));
        return recurse(0, 0, word1, word2);
    }
};

  