class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        map<int,vector<int>> m;
        for(int i=0;i<n;i++) m[arr[i]].push_back(i); 

        vector<int> visited(n, 0);
        vector<int> dist(n, 0);
        
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        dist[0] = 0;
        while(!q.empty()){
            int f = q.front(); q.pop();
            if(f-1 >= 0 and !visited[f - 1]) {
                q.push(f - 1); visited[f-1]=1; dist[f-1] = dist[f] + 1;
            }
            if(f+1 <n and !visited[f + 1]) {
                q.push(f + 1); visited[f+1]=1; dist[f+1] = dist[f] +1;
            }
            
            vector<int> sameValueNeigh = m[arr[f]];
            for(auto x: sameValueNeigh){
                if(!visited[x]){
                    q.push(x);
                    visited[x] = 1;
                    dist[x] = dist[f] + 1;
                }                    
            }
            // very important step as this converts TLE to Accepted.
            // as by erasing it, we are removing the cases, when same value 
            // iterate over the already iterated map vector. 
            m.erase(arr[f]);
        }
        
        return dist[n-1];
        
    }
};