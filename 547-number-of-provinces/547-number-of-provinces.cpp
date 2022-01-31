class Solution {
public:
    
    int find(int vertex, vector<int> &parents){
        if(parents[vertex] == -1) return vertex;
        return parents[vertex] = find(parents[vertex], parents);
    }
    
    void unionDSU(int i, int j, vector<int> &parents, vector<int> &ranks){
        int pi = find(i, parents);
        int pj = find(j, parents);
        
        if(pi==pj) return;
        if(ranks[i] < ranks[j]){
            parents[pi] = pj;
            ranks[pj] += ranks[pi]; 
        }else{
            parents[pj] = pi;
            ranks[pi] += ranks[pj];
        }
        return;
    } 
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        if(n==0) return 0;
        vector<int> parents(n,-1);
        vector<int> ranks(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    unionDSU(i,j,parents,ranks);
                }
            }
        }
        
        int cnt=0;
        for(auto x: parents){
            if(x==-1) cnt++;
        }
        
        return cnt;
        
    }
};