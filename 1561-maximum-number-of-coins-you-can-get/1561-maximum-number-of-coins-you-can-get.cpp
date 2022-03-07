class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int summ = 0;
        int i = 0;
        int j = n-1;
        while(i<=j){
            summ+= piles[j-1];
            j--; 
            j--;
            i++;
        }
        
        return summ;
    }
};