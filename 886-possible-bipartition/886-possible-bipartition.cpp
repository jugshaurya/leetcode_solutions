class Solution {
public:
    
    bool isBipartite(vector<vector<int>> &gr, vector<int>& visited,  vector<int>& color, int src, int c){
        visited[src] = 1;
        color[src] = c;
        
        for(auto nbr: gr[src]){
            if(!visited[nbr]){
                if(!isBipartite(gr, visited, color, nbr, c^1^2)) return false;
            }else{
                if(color[nbr] == c) return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> gr(n);
        for(auto x: dislikes){
            gr[x[0] - 1].push_back(x[1] - 1);
            gr[x[1] - 1].push_back(x[0] - 1);
        }
        
        vector<int> visited(n, 0);
        vector<int> color(n, 0);
        for(int i=0;i<n;i++){
            if (visited[i] == 0 and !isBipartite(gr,visited,color,i,1)) return false;
        }
        
        return true;
    }
};