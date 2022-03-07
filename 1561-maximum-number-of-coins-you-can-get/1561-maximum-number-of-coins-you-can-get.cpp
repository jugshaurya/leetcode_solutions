class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n= piles.size();
        int summ=0;
        int i=0;
        int j=n-1;
        while(i<=j){
            int a = piles[j--];
            int b = piles[j--];
            int c = piles[i++];
            summ+= b;
        }
        
        return summ;
    }
};