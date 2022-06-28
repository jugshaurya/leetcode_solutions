class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;i++) q.push(i);
        
        int cnt = k;
        while(q.size() > 1){
            cnt--;
            if(cnt == 0){
                q.pop();
                cnt = k;
            }else{
                q.push(q.front());
                q.pop();
            }
        }
        
        return q.front();
    }
};