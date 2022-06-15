const int INF = 1e9;

class Solution {
public:
    
    // just run dijkstra from k and fill in the dist vector
    // if even one of them is INF, return -1;
    // otherwise, return maximum of all. 
    
    // Note: times is a +ve quantity.
    // so it does not matter, whether we use visited or not.
    // visited prevents going in infinte loop, in case of -ve weight cycle.
    // but will lead to wrong results in almost all cases, if there is even a single -ve edge weights.
    
    // Dijkstra using set DS.
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> gr(n+1);
        for(auto x: times){
            gr[x[0]].push_back({x[1],x[2]});
        }
        
        set<pair<int, int> > s; // {dist, vertex}
        vector<int> dist(n+1, INF);
        dist[k] = 0;
        s.insert({dist[k], k});
        
        while(!s.empty()){
            auto [weighTillNow, node] = *s.begin();
            s.erase(s.begin());
            
            for(auto [child, childWeigh]: gr[node]){
                if(dist[child] > weighTillNow + childWeigh) {
                    s.erase({dist[child], child});
                    dist[child] = weighTillNow + childWeigh;
                    s.insert({dist[child], child});
                }
            }
        }
        
        
        int maxx = -1;
        for(int i = 0 ;i<=n;i++){
            if(i){
                if(dist[i]==INF) return -1;
                maxx = max(maxx, dist[i]);
            }
        }
            
        return maxx;
    }
};